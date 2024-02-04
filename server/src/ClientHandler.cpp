/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** ClientHandler.cpp
*/

#include "../includes/MultiClientServer.hpp"
#include "../includes/ClientHandler.hpp"
#include "../../common/Message.hpp"
#include <boost/asio/read_until.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <asio.hpp>

namespace Babel::Server::Network
{
    ClientHandler::ClientHandler(asio::io_context &ioContext, MultiClientServer &server): socket_(ioContext, asio::ip::tcp::socket::endpoint_type()) {
        this->iocontext_ = &ioContext;
        this->server_ = &server;
    }

    ClientHandler *ClientHandler::create_instance(asio::io_context &ioContext, MultiClientServer &server) {
        return new ClientHandler(ioContext, server);
    }

    ClientHandler *ClientHandler::get_handler() {
        return this;
    }

    void ClientHandler::start(asio::ip::tcp::socket &socket) {
        this->socket_ = std::move(socket);
        doRead();
        doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::LOG_ACK, "Welcome to Malek's Server"));
    }

    void ClientHandler::doSend(BabelProtocol::Message msg)
    {
        std::vector<char> binaryData = msg.serialize();


        auto buffer = std::make_shared<std::vector<char>>(std::move(binaryData));



        asio::async_write(socket_, asio::buffer(*buffer),
                          [this](const asio::error_code &ec, std::size_t bytes_transferred) {
                              if (!ec) {
                                  WriteHandler(ec, bytes_transferred);
                              } else {
                                  std::cout << "Error of connexion (doSend): " << ec.message() << std::endl;
                              }
                          });
    }

    void ClientHandler::WriteHandler(const boost::system::error_code& err, size_t bytes_transferred)
    {
        (void)bytes_transferred;
        if (!err)
            doRead();
    }

    void ClientHandler::disconnect()
    {
        socket_.close();
        server_->disconnect_client(get_handler());
    }

    void ClientHandler::doRead() {
        _read.clear();
        asio::async_read_until(socket_, response_, "\0",
           [this](const asio::error_code &ec, std::size_t bytes_transferred) {
               if (!ec) {
                   ReadHandler(ec, bytes_transferred);
               } else {
                   std::cout << "Error of Connection (doRead): " << ec.message() << std::endl;
                   disconnect();
               }
           });
    }

    void ClientHandler::ReadHandler(const boost::system::error_code& err, std::size_t bytes_transferred)
    {
        (void)bytes_transferred;
        _message.clear();
        if (!err) {
            std::istream is(&response_);
            std::string line;
            std::getline(is, line);
            _read = std::vector<char>(line.begin(), line.end());
            _message = BabelProtocol::Message(_read);
            TreatRequest(_message);
        } else {
            disconnect();
            return;
        }
        doRead();
    }

    asio::io_context &ClientHandler::get_io_context() const {
        return *iocontext_;
    }

    Babel::Client_Data ClientHandler::getClient() const {
        return this->client_;
    }

    void ClientHandler::setClient(Client_Data &client) {
        this->client_ = client;
    }

    asio::ip::tcp::socket &ClientHandler::get_socket() {
        return this->socket_;
    }

    // ============================================== COMMANDS ==============================================
    void ClientHandler::LogCmd(BabelProtocol::Message msg)
    {
        // msg = username:password
        std::vector<Client_Data> clients = server_->getClientData();
        std::vector<std::string> temp = Babel::Server::Network::ClientHandler::split(msg.getData(), ":");
        for (auto &client : clients) {
            if (client.getUsername() == temp[0] && client.getPassword() == temp[1]) {
                this->client_ = client;
                std::vector<char> charVector = client.serialize();
                std::string str(charVector.begin(), charVector.end());
                //TODO: all user
                this->doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::LOG_DATA, str));
                this->client_.setStatus("online");
                return;
            }
            if (client.getUsername() == temp[0] && client.getPassword() != temp[1]) {
                this->doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::ERROR_LOG, "Wrong Password"));
                return;
            }
        }
        this->doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::ERROR_LOG, "User not found"));
    }

    void ClientHandler::RegisterCmd(BabelProtocol::Message msg)
    {
        std::cout << "RegisterCmd: " << msg.getData() << std::endl;
        // msg = username:password
        std::vector<Babel::Client_Data> clients = server_->getClientData();
        std::vector<std::string> temp = Babel::Server::Network::ClientHandler::split(msg.getData(), ":");
        for (auto &client : clients) {
            if (client.getUsername() == temp[0]) {
                this->doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::ERROR_REGISTER, "User already exist"));
                return;
            }
        }
        this->server_->setClientData(this->server_->getDb().insertUser(Babel::Client_Data(temp[0], temp[1], 0)));
        LogCmd(msg);
    }

    void ClientHandler::CallRequestCmd(BabelProtocol::Message msg)
    {
        //cmd /call melissa
        //msg = melissa:my_port:my_ip:
        std::vector<Babel::Client_Data> clients = server_->getClientData();
        std::vector<std::string> temp = Babel::Server::Network::ClientHandler::split(msg.getData(), ":");
        std::string str = temp[0];

        if (str == client_.getUsername()) {
            doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::ERROR_CALL_REQUEST, "You can't call yourself"));
        }
        for (auto &client : clients) {
            if (client.getUsername() == str) {
                if (client.getStatus() == "online") {
                    std::string username = client_.getUsername();
                    this->server_->doSendToClient(client, Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::CALL_REQUEST,
                                                                                        "call incoming from " +  username + ":" + temp[1] + ":" + temp[2]), client_.getUsername());
                    doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::CALLING, "Calling " + str + "..." ));
                } else {
                    doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::ERROR_CALL_REQUEST, "You can't call " + str + " because he is " + client.getStatus() + "."));
                }
            }
        }
    }

    void ClientHandler::CallResponseCmd(BabelProtocol::Message msg)
    {
        //(accept or refuse):username:user_port:user_ip:myp_port:my_ip
        std::vector<std::string> temp = Babel::Server::Network::ClientHandler::split(msg.getData(), ":");

        for (auto &client : server_->getClientData()) {
            if (client.getUsername() == temp[1]) {
                if (temp[0] == "accept") {
                    std::string us = client_.getUsername();
                    std::string current_client_call_data = temp[2] + ":" + temp[3];
                    std::string other_client_call_data =  temp[4] + ":" + temp[5];
                    this->server_->doSendToClient(client, Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::CALL_ACCEPTED, current_client_call_data), us);
                    doSend(BabelProtocol::Message(BabelProtocol::Message::MessageType::CALL_ACCEPTED, other_client_call_data));
                    client_.setStatus("busy");
                    client.setStatus("busy");
                } else {
                    server_->doSendToClient(client, Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::CALL_REJECTED, "Call rejected"), client_.getUsername());
                }
            }
        }
    }

    void ClientHandler::CallEndCmd(BabelProtocol::Message msg)
    {
        //msg = username
        std::vector<Babel::Client_Data> clients = server_->getClientData();
        std::string str = msg.getData();

        for (auto &client : clients) {
            if (client.getUsername() == str) {
                this->server_->doSendToClient(client, Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::CALL_END, "Call ended"), client_.getUsername());
            }
        }
    }

    void ClientHandler::LogoutCmd(BabelProtocol::Message msg)
    {
        client_.setStatus("offline");
    }

    void ClientHandler::DisconnectCmd(BabelProtocol::Message msg)
    {
        //this->disconnect();
        client_.setStatus("offline");
    }

    void ClientHandler::TreatRequest(BabelProtocol::Message msg)
    {
        BabelProtocol::Message::MessageType type = msg.getType();

        if (type == BabelProtocol::Message::MessageType::REGISTER)
        {
            this->RegisterCmd(msg);
        }
        else if (type == BabelProtocol::Message::MessageType::LOG)
        {
            this->LogCmd(msg);
        }
        else if (type == BabelProtocol::Message::MessageType::CALL_REQUEST)
        {
            this->CallRequestCmd(msg);
        }
        else if (type == BabelProtocol::Message::MessageType::CALL_RESPONSE)
        {
            this->CallResponseCmd(msg);
        }
        else if (type == BabelProtocol::Message::MessageType::CALL_END)
        {
            this->CallEndCmd(msg);
        }
        else if (type == BabelProtocol::Message::MessageType::DISCONNECT)
        {
            this->DisconnectCmd(msg);
        }
        else if (type == BabelProtocol::Message::MessageType::LOG_OUT)
        {
            this->LogoutCmd(msg);
        }
        else
        {
            std::cout << "Unknown command" << std::endl;
        }
    }
}
