#include <asio.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Session : public std::enable_shared_from_this<Session>
{
    public:
        Session(asio::ip::tcp::socket socket)
        : socket_(std::move(socket))
        {
            ;
        }

        void start() {
            std::cout << "Nouvelle connexion cliente." << std::endl;
            doReadHeader();
        }

    private:
        void doReadHeader() {
            std::cout << "Attente du header du message." << std::endl;
            auto self(shared_from_this());
            asio::async_read(socket_, asio::buffer(&messageSize_, sizeof(messageSize_)), [this, self](const asio::error_code &ec, size_t length) {
                if (!ec) {
                    std::cout << "Header reçu du client : " << messageSize_ << std::endl;
                    doReadBody();
                } else {
                    // Gérer la déconnexion du client ou toute autre erreur
                    std::cout << "Client déconnecté." << std::endl;
                }
            });
        }

        void doReadBody() {
            std::cout << "Lecture du corps du message." << std::endl;
            auto self(shared_from_this());
            message_.resize(messageSize_);

            asio::async_read(socket_, asio::buffer(message_), [this, self](const asio::error_code &ec, size_t length) {
                if (!ec) {
                    std::cout << "Message reçu du client : "
                              << std::string(message_.begin(), message_.end())
                              << std::endl;
                    handleMessage();
                    doReadHeader(); // Continue à lire les messages
                } else {
                    // Gérer la déconnexion du client ou toute autre erreur
                    std::cout << "Client déconnecté." << std::endl;
                }
            });
        }


        void handleMessage() {
          std::cout << "Traitement du message." << std::endl;
          // Implémentez votre logique de gestion des messages ici.
          // Dans cet exemple, nous affichons simplement le message reçu.
        }

        asio::ip::tcp::socket socket_;
        uint32_t messageSize_;
        std::vector<char> message_;
};

class Server {
    public:
        Server(asio::io_context &ioContext, short port)
        : acceptor_(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)),  socket_(ioContext){
            doAccept();
        }

    private:
        void doAccept() {
            acceptor_.async_accept(socket_, [this](const asio::error_code &ec) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket_))->start();
                }
                doAccept(); // Accepter la prochaine connexion
            });
        }

        asio::ip::tcp::acceptor acceptor_;
        asio::ip::tcp::socket socket_;
};

int main() {
  try {
    asio::io_context ioContext;
    Server server(ioContext, 8080);

    std::cout << "Serveur en attente de connexions sur le port 8080..."
              << std::endl;

    ioContext.run();
  } catch (const std::exception &e) {
    std::cerr << "Exception : " << e.what() << std::endl;
  }

  return 0;
}
