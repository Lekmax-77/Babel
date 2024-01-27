#include <iostream>
#include <vector>
#include <asio.hpp>

namespace Server {

    class MultiClientServer {
    public:
        MultiClientServer(asio::io_context &ioContext, short port)
            : acceptor_(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), nextClientId_(1)
        {
            std::cout << "Launching Server on " << port << " port" << std::endl;
            doAccept();
            startConsoleInput(ioContext);
        }

    private:
        void doAccept()
        {
            acceptor_.async_accept(
                [this](const asio::error_code &ec, asio::ip::tcp::socket socket)
                {
                    if (!ec)
                    {
                        std::cout << "Nouveau client connecté." << std::endl;

                        auto client = std::make_shared<ClientHandler>(std::move(socket), nextClientId_++);
                        client->start();
                        clients_.push_back(client);
                    }

                    doAccept();
                });
        }

        void startConsoleInput(asio::io_context &ioContext)
        {
            std::thread([this, &ioContext]()
                        {
                            while (true)
                            {
                                std::string input;
                                std::cout << "&> ";
                                std::getline(std::cin, input);

                                if (input == "exit")
                                {
                                    // Fermer toutes les connexions et arrêter le serveur
                                    ioContext.post([this]()
                                                   {
                                                       for (auto &client : clients_)
                                                       {
                                                           client->disconnect();
                                                       }
                                                       clients_.clear();
                                                       acceptor_.close();
                                                   });
                                    break;
                                }

                                // Envoyer le message à tous les clients
                                ioContext.post([this, input]()
                                               {
                                                   for (auto &client : clients_)
                                                   {
                                                       client->doWrite(input);
                                                   }
                                               });
                            }
                        })
                .detach();
        }

    public:
        class ClientHandler : public std::enable_shared_from_this<ClientHandler>
        {
        public:
            explicit ClientHandler(asio::ip::tcp::socket socket, int clientId)
                : socket_(std::move(socket)), clientId_(clientId) {}

            void start()
            {
                doRead();
            }

            void disconnect()
            {
                // Implement disconnect logic here
            }

        
            void doRead()
            {
                asio::async_read(
                    socket_, asio::buffer(buffer_),
                    [self = shared_from_this()](const asio::error_code &ec, std::size_t bytesTransferred)
                    {
                        if (!ec)
                        {
                            // TODO: Traitement du message reçu (buffer_ contient les données)
                            std::cout << "Message reçu : " << std::string(self->buffer_.begin(), self->buffer_.begin() + bytesTransferred) << std::endl;
                            // Continuer la lecture pour recevoir le prochain message
                            self->doRead();
                        }
                        else
                        {
                            // Gérer les erreurs de lecture ou la déconnexion du client
                            self->handleError(ec);
                        }
                    });
            }

            void doWrite(const std::string &message)
            {
                // Convertir la chaîne de caractères en un vecteur d'octets
                std::vector<uint8_t> messageBytes(message.begin(), message.end());

                // Ajouter la taille du message au début du vecteur
                std::uint32_t messageSize = messageBytes.size();
                std::vector<uint8_t> messageWithSize;
                messageWithSize.insert(messageWithSize.end(), reinterpret_cast<uint8_t *>(&messageSize), reinterpret_cast<uint8_t *>(&messageSize) + sizeof(std::uint32_t));
                messageWithSize.insert(messageWithSize.end(), messageBytes.begin(), messageBytes.end());

                // Envoyer le message au client
                asio::async_write(
                    socket_, asio::buffer(messageWithSize),
                    [self = shared_from_this()](const asio::error_code &ec, std::size_t /*bytes_transferred*/)
                    {
                        if (ec)
                        {
                            // Gérer les erreurs d'écriture ou la déconnexion du client
                            self->handleError(ec);
                        }
                    });
            }
            protected:

            void handleError(const asio::error_code &ec)
            {
                if (ec != asio::error::eof && ec != asio::error::connection_reset)
                {
                    std::cerr << "Erreur : " << ec.message() << std::endl;
                }

                // TODO: Gérer la déconnexion du client

                // Retirer le client de la liste
                auto it = std::find(clients_.begin(), clients_.end(), shared_from_this());
                if (it != clients_.end())
                {
                    clients_.erase(it);
                }
            }

        private:
            asio::ip::tcp::socket socket_;
            int clientId_;
            std::array<uint8_t, 1024> buffer_;
        };

    private:
        asio::ip::tcp::acceptor acceptor_;
        int nextClientId_;
        static std::vector<std::shared_ptr<ClientHandler>> clients_;
    };

    std::vector<std::shared_ptr<Server::MultiClientServer::ClientHandler>> Server::MultiClientServer::clients_;

} /* namespace Server */
