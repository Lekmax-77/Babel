#include <iostream>
#include <asio.hpp>

// Fonction pour convertir l'endianness (host to network)
uint32_t convertToNetworkOrder(uint32_t value) {
    return htonl(value);
}

// Fonction pour convertir l'endianness (network to host)
uint32_t convertToHostOrder(uint32_t value) {
    return ntohl(value);
}

class Client {
public:
    Client(asio::io_context& ioContext, const std::string& host, short port)
        : socket_(ioContext), inputBuffer_(), outputBuffer_() {
        // Résolution de l'adresse IP du serveur
        asio::ip::tcp::resolver resolver(ioContext);
        auto endpoints = resolver.resolve(host, std::to_string(port));

        // Connexion au serveur
        asio::connect(socket_, endpoints);

        // Lancer la lecture en arrière-plan
        doRead();
    }

    void run() {
        // Lancer la saisie utilisateur en arrière-plan
        doWrite();
    }

private:
    void doRead() {
        asio::async_read_until(socket_, inputBuffer_, '\n',
            [this](const asio::error_code& ec, std::size_t /*length*/) {
                if (!ec) {
                    handleRead();
                    doRead();
                } else {
                    // Gérer la déconnexion du serveur ou toute autre erreur
                    std::cerr << "Erreur de lecture : " << ec.message() << std::endl;
                }
            });
    }

    void handleRead() {
        // Lire les données du buffer
        std::string message(asio::buffers_begin(inputBuffer_.data()),
                            asio::buffers_end(inputBuffer_.data()));

        // Afficher le message reçu
        std::cout << "Message du serveur : " << message;

        // Effacer le buffer d'entrée
        inputBuffer_.consume(inputBuffer_.size());
    }

    void doWrite() {
        // Lire l'entrée utilisateur depuis le terminal
        std::cout << "&> ";
        std::getline(std::cin, userInput_);
        size_t len = userInput_.length();
        uint32_t networkOrderSize = convertToNetworkOrder(len); // Convertir de host à network

        // Envoyer les données au serveur
        asio::async_write(socket_, asio::buffer(&networkOrderSize, sizeof(networkOrderSize)),
            [this](const asio::error_code& ec, std::size_t length) {
                if (!ec) {
                    asio::async_write(socket_, asio::buffer(userInput_ + '\n'),
                        [this](const asio::error_code& ec, std::size_t length) {
                            if (!ec) {
                                // Continuer la saisie utilisateur
                                doWrite();
                            } else {
                                // Gérer la déconnexion du serveur ou toute autre erreur
                                std::cerr << "Erreur d'écriture : " << ec.message() << std::endl;
                            }
                        });
                } else {
                    // Gérer la déconnexion du serveur ou toute autre erreur
                    std::cerr << "Erreur d'écriture : " << ec.message() << std::endl;
                }
            });
    }

    asio::ip::tcp::socket socket_;
    asio::streambuf inputBuffer_;
    asio::streambuf outputBuffer_;
    std::string userInput_;
};

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            std::cerr << "Usage : ./client <host> <port>" << std::endl;
            return 1;
        }

        asio::io_context ioContext;
        Client client(ioContext, argv[1], std::stoi(argv[2]));
        client.run();
        ioContext.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }

    return 0;
}
