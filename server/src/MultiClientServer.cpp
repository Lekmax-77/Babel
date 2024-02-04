/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** MultiClientServer
*/

#include "MultiClientServer.hpp"
#include <iostream>
#include <vector>

namespace Babel::Server::Network
{
    MultiClientServer::MultiClientServer(asio::io_context &ioContext, short port)
    : socket_(ioContext),
    acceptor_(ioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), _db()
    {
        this->_client_data = _db.getUsers();
        this->_port = port;
        try {
            this->iocontext_ = &ioContext;
            doAccept();

        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            throw;
        }
    }

    MultiClientServer::~MultiClientServer()
    {
        std::cout << "Server closed" << std::endl;
    }

    void MultiClientServer::run()
    {
        std::cout << "Running Server on " << _port << " port" << std::endl;
        this->iocontext_->run();
    }

    MultiClientServer *MultiClientServer::get_server() const
    {
        return const_cast<MultiClientServer *>(this);
    }


    void MultiClientServer::disconnect_client(ClientHandler *client)
    {
        auto it = std::find(clients_.begin(), clients_.end(), client);
        if (it != clients_.end())
        {
            clients_.erase(it);
        }
    }

    void MultiClientServer::doAccept()
    {
        acceptor_.async_accept(socket_, [this](const asio::error_code &ec) {
            if (!ec) {
                if (socket_.is_open()) {
                    if (clients_.size() < MAX_SIMULTANEOUS_CONNECTIONS) {
                        auto clientHandler = ClientHandler::create_instance(
                                *iocontext_, *this);
                        clientHandler->start(socket_);
                        clients_.push_back(clientHandler);
                    } else {
                        std::cerr << "Max simultaneous connections reached" << std::endl;
                        socket_.close();
                    }
                }
            }
            doAccept();
        });
    }


    void MultiClientServer::doSendToClient(Babel::Client_Data client, Babel::BabelProtocol::Message msg, std::string username_sender)
    {
        (void)username_sender;
        for (auto &c : clients_) {
            if (c->getClient().getUsername() == client.getUsername()) {
                c->get_handler()->doSend(msg);
            }
        }
    }
} // namespace Babel