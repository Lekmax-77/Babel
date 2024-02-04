#include <iostream>
#include <asio.hpp>



namespace Client {
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
                : socket_(ioContext), inputBuffer_(), outputBuffer_()
                {
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
            void doRead()
            {
                asio::async_read_until(socket_, inputBuffer_, '\0',
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
                std::cout << "TODO: Gerer Les Message du serveur : " << message;

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
} // namespace Client













#include <iostream>
#include <vector>
#include <string>

// Interface générique pour les clients réseau
class NetworkClient {
public:
    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    virtual bool isConnected() const = 0;
    virtual bool sendMessage(const std::string& message) = 0;
    virtual std::vector<std::string> receiveMessages() = 0;
};

// Gestionnaire réseau générique
class NetworkManager {
public:
    NetworkManager(NetworkClient* client) : client(client) {}

    // Méthode pour ajouter un message au buffer d'envoi
    void addToSendBuffer(const std::string& message) {
        sendBuffer.push_back(message);
    }

    // Méthode pour récupérer la liste des derniers messages envoyés
    std::vector<std::string> getSentMessages() const {
        return sentMessages;
    }

    // Méthode pour vider le buffer après l'envoi des messages
    void clearSendBuffer() {
        sendBuffer.clear();
    }

    // Méthode pour envoyer les messages du buffer
    void doWrite() {
        if (!client->isConnected()) {
            std::cout << "Error: Not connected to the server." << std::endl;
            return;
        }

        for (const auto& message : sendBuffer) {
            if (client->sendMessage(message)) {
                sentMessages.push_back(message);
            } else {
                std::cout << "Error sending message: " << message << std::endl;
            }
        }

        clearSendBuffer();
    }

    // Méthode pour recevoir les messages du client
    void doRead() {
        if (!client->isConnected()) {
            std::cout << "Error: Not connected to the server." << std::endl;
            return;
        }

        auto receivedMessages = client->receiveMessages();
        // Traitez les messages reçus comme nécessaire

        // Nettoyez le buffer après la lecture des messages
        // (vous devrez implémenter la logique appropriée pour votre cas d'utilisation)
        // clearReceiveBuffer();
    }

private:
    NetworkClient* client;
    std::vector<std::string> sendBuffer;
    std::vector<std::string> sentMessages;
};

// Exemple de client réseau TCP
class TcpNetworkClient : public NetworkClient {
public:
    // Implémentation des méthodes virtuelles de NetworkClient
    bool connect() override {
        // Logique de connexion TCP
        return true;
    }

    void disconnect() override {
        // Logique de déconnexion TCP
    }

    bool isConnected() const override {
        // Vérifier l'état de la connexion TCP
        return true;
    }

    bool sendMessage(const std::string& message) override {
        // Logique d'envoi de message via TCP
        return true;
    }

    std::vector<std::string> receiveMessages() override {
        // Logique de réception de messages via TCP
        return {"Received message 1", "Received message 2"};
    }
};
