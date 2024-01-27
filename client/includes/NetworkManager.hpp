/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** NetworkManager
*/

#ifndef NETWORKMANAGER_HPP_
    #define NETWORKMANAGER_HPP_
    #include <iostream>
    #include <vector>
    #include <netinet/in.h>
    #include <asio.hpp>

namespace Client {

    class INetworkManager {
        public:
            virtual ~INetworkManager() = default;

            virtual void doRead() = 0;
            virtual void doWrite() = 0;
            virtual void connect() = 0;
            virtual void disconnect() = 0;
            virtual bool isConnected() const = 0;

            virtual int getPort() const = 0;
            virtual void setPort(int port) = 0;
            virtual std::string getIp() const = 0;
            virtual void setIp(std::string ip) = 0;
            virtual void send_message(std::vector<uint8_t> &message) = 0;
            virtual std::vector<std::vector<uint8_t>>receive_message() = 0;
    };

    class ANetworkManager: public INetworkManager
    {
        public:

            ANetworkManager() = default;

            ~ANetworkManager() = default;

            ANetworkManager(const ANetworkManager &other) = default;

            ANetworkManager(std::string ip, int port)
            {
                _ip = ip;
                _port = port;
            }

            int getPort() const
            {
                return _port;
            }

            void setPort(int port)
            {
                _port = port;
                this->connect();
            }

            std::string getIp() const
            {
                return _ip;
            }

            void setIp(std::string ip)
            {
                _ip = ip;
                this->connect();
            }
            
            void send_message(std::vector<uint8_t> &message)
            {
                _sentMessages.push_back(message);
            }
            
            std::vector<std::vector<uint8_t>> receive_message()
            {
                std::vector<std::vector<uint8_t>> buffer = _receiveBuffer;
                _receiveBuffer.clear();
                return buffer;
            }

            virtual void doRead() = 0;

            virtual void doWrite() = 0;

            virtual void connect() = 0;

            virtual void disconnect() = 0;

            bool isConnected() const
            {
                return _connected;
            }

            std::vector<std::vector<uint8_t>> getSentMessages()
            {
                std::vector<std::vector<uint8_t>> sentmessage = _sentMessages;
                _sentMessages.clear();
                return sentmessage;
            }

            void clearSendBuffer()
            {
                _sentMessages.clear();
            }

            void clearReceiveBuffer()
            {
                _receiveBuffer.clear();
            }



        protected:
            int _port;
            bool _connected;
            std::string _ip;
            std::vector<std::vector<uint8_t>> _sentMessages;
            std::vector<std::vector<uint8_t>> _receiveBuffer;
        private:
    };


    class AsioNetworkManager : public ANetworkManager
    {
        public:
            //asio::io_context& ioContext
            AsioNetworkManager(asio::io_context& ioContext, std::string ip, int port) : ANetworkManager(ip, port), socket_(ioContext), inputBuffer_(), outputBuffer_()
            {
                // Résolution de l'adresse IP du serveur
                asio::ip::tcp::resolver resolver(ioContext);
                auto endpoints = resolver.resolve(ip, std::to_string(port));

                // Connexion au serveur
                asio::connect(socket_, endpoints);
                //TODO: if trobble, try to connect again 5 second later,  try to connect 3 times, if still trobble, throw exception


                // Lancer la lecture en arrière-plan
                doRead();
            }
        
            void doRead()
            {
                std::uint32_t _currentMessageSize = 0;
            
                // Première lecture pour obtenir la taille du message
                asio::async_read(socket_, asio::buffer(&_currentMessageSize, sizeof(uint32_t)),
                    [this, _currentMessageSize](const asio::error_code& ec, std::size_t /*bytes_transferred*/)
                    {
                        if (!ec) {
                            std::cout << "Message size : " << _currentMessageSize << std::endl;
                            std::uint32_t _newcurrentMessageSize = ntohl(_currentMessageSize);
            
                            std::vector<uint8_t> _currentMessage(_newcurrentMessageSize);
            
                            // Deuxième lecture pour obtenir le message complet
                            asio::async_read(socket_, asio::buffer(_currentMessage),
                                [this, _currentMessage, _currentMessageSize](const asio::error_code& ec, std::size_t /*bytes_transferred*/)
                                {
                                    if (!ec) {
                                        this->_receiveBuffer.push_back(_currentMessage);
            
                                        // TODO: Traitement du message complet (dans _currentMessage)
            
                                        std::string str(reinterpret_cast<const char*>(_currentMessage.data()), _currentMessage.size());
            
                                        // Afficher la chaîne résultante
                                        std::cout << "Message reçu : " << str << std::endl;
            
                                        // Continuer la lecture
                                        doRead();
                                    } else {
                                        // TODO: Gérer les erreurs de lecture
                                    }
                                });
                        } else {
                            // TODO: Gérer les erreurs de lecture
                        }
                    });
            }



//handle message, maybe CLient herited AsioNetworkManager and implement this function

            void doWrite()
            {
                if (!_sentMessages.empty()) {

                    std::cout << "do Write" << std::endl;
                    // Récupérer le premier message dans la liste
                    std::vector<uint8_t>& messageToSend = _sentMessages[0];

                    // Ajouter la taille du message au début du vecteur
                    std::vector<uint8_t> messageWithSize;
                    std::uint32_t messageSize = messageToSend.size();
                    messageWithSize.insert(messageWithSize.end(), reinterpret_cast<uint8_t*>(&messageSize), reinterpret_cast<uint8_t*>(&messageSize) + sizeof(std::uint32_t));
                    messageWithSize.insert(messageWithSize.end(), messageToSend.begin(), messageToSend.end());

                    // Ajouter le caractère nul à la fin
                    messageWithSize.push_back('\0');

                    // Envoyer le message
                    asio::async_write(socket_, asio::buffer(messageWithSize),
                        [this](const asio::error_code& ec, std::size_t /*bytes_transferred*/)
                        {
                            if (!ec) {
                                _sentMessages.erase(_sentMessages.begin());
                            } else {
                                // TODO: Gérer les erreurs d'écriture
                            }
                            doWrite();
                        });
                }
            }

            void disconnect()
            {
                if (_connected)
                {
                    _connected = false;
                    asio::post(socket_.get_executor(), [this]() { socket_.close(); });
                    this->clearSendBuffer();
                    this->clearReceiveBuffer();
                }
            }

            void connect()
            {
                this->disconnect();

                // Perform connection/reconnection
                asio::ip::tcp::resolver resolver(socket_.get_executor());
                auto endpoints = resolver.resolve(getIp(), std::to_string(getPort()));

                asio::async_connect(socket_, endpoints,
                    [this](const asio::error_code& ec, asio::ip::tcp::endpoint)
                    {
                        if (!ec)
                        {
                            _connected = true;
                            // TODO: Handle successful connection
                        }
                        else
                        {
                            // TODO: Handle connection error
                        }
                });
            }
        protected:
        private:
            asio::ip::tcp::socket socket_;
            asio::streambuf inputBuffer_;
            asio::streambuf outputBuffer_;
    };
} // namespace Client

#endif /* !NETWORKMANAGER_HPP_ */
