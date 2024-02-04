/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** NetworkManager
*/


#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <netinet/in.h>
#include <asio.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/buffer.hpp>
#include "../../common/Message.hpp"
#include "Cli.hpp"


namespace Babel::Client
{
    class Cli; // Forward declaration

    class INetworkManager
    {
        public:
            virtual ~INetworkManager() = default;

            virtual void doSend(const BabelProtocol::Message &msg) = 0;

            virtual void connect() = 0;

            virtual asio::io_context &getIoContext() = 0;
    };

    class AsioNetworkManager : public INetworkManager, public std::enable_shared_from_this<AsioNetworkManager>
    {
        public:

            AsioNetworkManager(Cli &client, const std::string &ip, int port);

            ~AsioNetworkManager() override;

            void doSend(const BabelProtocol::Message& msg) override;

            void doRead();

            void ReadHandler(const asio::error_code& err, std::size_t bytes_transferred);

            void disconnect();

            void connect() override;

            asio::io_context &getIoContext() override;


        private:
            asio::streambuf _response{4096};
            std::vector<std::vector<uint8_t>> _sentMessages;
            std::vector<char> _read;
            asio::streambuf _inputBuffer;
            std::istream _inputStream{&_inputBuffer};


            BabelProtocol::Message _message;
            asio::io_context _ioContext;
            asio::ip::tcp::socket _socket;
            std::string _ip;
            int _port;
            bool _connected;
            std::string _my_ip;

            asio::ip::tcp::resolver _resolver;
            Cli *_client;
    };



} // namespace Babel::Client
