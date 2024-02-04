/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** NetworkManager.cpp
*/

#include "../includes/NetworkManager.hpp"

namespace Babel::Client
{
    AsioNetworkManager::AsioNetworkManager(Cli &client, const std::string &ip, int port)
            : _ioContext(), _socket(_ioContext), _ip(ip), _port(port), _connected(false), _resolver(_ioContext), _client(&client)
    {
        _my_ip = "127.0.0.1";
    }

    AsioNetworkManager::~AsioNetworkManager()
    {
        disconnect();
    }

    void AsioNetworkManager::doSend(const Babel::BabelProtocol::Message &msg)
    {
        std::vector<char> _sentMessages = msg.serialize();

        asio::async_write(_socket, asio::buffer(_sentMessages),
                          [this](const asio::error_code &ec, std::size_t bytes_transferred)
                          {
                              (void)bytes_transferred;
                              if (ec)
                              {
                                  std::cerr << "Error: " << ec.message() << std::endl;
                                  disconnect();
                                  exit(1);
                              }
                          });
    }

    void AsioNetworkManager::doRead()
    {
        asio::async_read_until(_socket, _response, "\0", [this](const asio::error_code &err, std::size_t bytes_transferred)
                               { ReadHandler(err, bytes_transferred); });
    }

    void AsioNetworkManager::ReadHandler(const asio::error_code &err, std::size_t bytes_transferred)
    {
        (void)bytes_transferred;
        _message.clear();
        if (!err)
        {
            std::istream is(&_response);
            std::string line;
            std::getline(is, line);
            _read = std::vector<char>(line.begin(), line.end());
            _message = BabelProtocol::Message(_read);
            _client->TreatRequest(_message);
            this->doRead();
        }
        else
        {
            disconnect();

            exit(1);
        }
        doRead();
    }

    void AsioNetworkManager::disconnect()
    {

        std::cout << "disconnect" << std::endl;
        this->doSend(BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::DISCONNECT));
        if (_connected)
        {
            _connected = false;
            asio::post(_socket.get_executor(), [this]()
                       { _socket.close(); });
            std::cout << "Disconnected from server" << std::endl;
        }
    }

    void AsioNetworkManager::connect()
    {
        if (_connected)
            disconnect();
        try {
            auto endpoints = _resolver.resolve(_ip, std::to_string(_port));

            asio::ip::tcp::resolver::query my_query(asio::ip::host_name(), "");

            asio::ip::tcp::resolver::iterator ip_endpoints = _resolver.resolve(my_query);
            asio::ip::tcp::endpoint ip_endpoint = *ip_endpoints;
            _my_ip = ip_endpoint.address().to_string();

            asio::connect(_socket, endpoints);
            std::cout << "Connected to Server" << std::endl;
            _connected = true;
            try
            {
                doRead();
            }
            catch (std::exception &e)
            {
                std::cerr << "error connect:doread " << e.what() << std::endl;
                exit(1);
            }
        }
        catch (std::exception &e)
        {
            std::cerr << "error connect " << e.what() << std::endl;
            exit(1);
        }
    }

    asio::io_context &AsioNetworkManager::getIoContext()
    {
        return _ioContext;
    }


}