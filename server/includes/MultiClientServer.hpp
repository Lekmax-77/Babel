/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** MultiClientServer
*/

#pragma once

#include <iostream>
#include <vector>
#include <netinet/in.h>
#include <asio.hpp>
#include "ClientHandler.hpp"
#include "DatabasesSqlite.hpp"
#include <memory>
#include "../../common/Client.hpp"

#define MAX_SIMULTANEOUS_CONNECTIONS 100

namespace Babel::Server::Network
        {
            /**
             * @brief This class is the server that will handle all the clients connections
             * 
             */
            class MultiClientServer: public std::enable_shared_from_this<MultiClientServer>
            {
                public:

                    /**
                     * @brief Construct a new Multi Client Server object
                     * 
                     * @param ioContext is the asio context
                     * @param port is the port on which the server will listen
                     */
                    MultiClientServer(asio::io_context &ioContext, short port);


                    /**
                     * @brief Destroy the Multi Client Server object
                     * 
                     */
                    ~MultiClientServer();

                    /**
                     * @brief This function will run the server
                     * 
                     */
                    void run();

                    /**
                     * @brief Get the server object
                     * 
                     * @return Babel::Server::Network::MultiClientServer* 
                     */
                    MultiClientServer *get_server() const;

                    /**
                     * @brief This function will disconnect a client from the server
                     * 
                     * @param client is the client to disconnect
                     */
                    void disconnect_client(ClientHandler *client);

                    /**
                     * @brief This function will set the database of the server
                     *
                     * @param db is the database of the server
                     */
                    void setDb(SQLiteDatabase db) { _db = db; }

                    /**
                     * @brief This function will return the database of the server
                     *
                     * @return SQLiteDatabase is the database of the server
                     */
                    SQLiteDatabase getDb() { return _db; }

                    /**
                     * @brief This function will return the list of all the clients data
                     *
                     * @return std::vector<Client> is the list of all the clients data
                     */
                    std::vector<Babel::Client_Data> getClientData() { return _client_data; }

                    /**
                     * @brief This function will set the list of all the clients data
                     *
                     * @param client_data is the list of all the clients data
                     */
                    void setClientData(std::vector<Babel::Client_Data> client_data) { _client_data = client_data; }

                    /**
                     * @brief This function will send a message to a client
                     *
                     * @param client is the client to send the message to
                     * @param msg is the message to send
                     * @param username_sender is the username of the sender
                     */
                    void doSendToClient(Babel::Client_Data client, Babel::BabelProtocol::Message msg, std::string username_sender);
                private:

                    /**
                     * @brief This function will accept a new client connection
                     * 
                     */
                    void doAccept();




                private:
                    /**
                     * @brief This is the asio context
                     * 
                     */
                    asio::io_context *iocontext_;

                    /**
                     * @brief This is the socket on which the server will listen
                     * 
                     */
                    asio::ip::tcp::socket socket_;

                    /**
                     * @brief This is the acceptor that will accept the new connections
                     * 
                     */
                    asio::ip::tcp::acceptor acceptor_;

                    /**
                     * @brief This is the list of all the clients connected to the server
                     * 
                     */
                    std::vector<ClientHandler *> clients_;

                    /**
                     * @brief This is the port on which the server will listen
                     * 
                     */
                    short _port;

                    /**
                     * @brief This is the database of the server
                     *
                     */
                    SQLiteDatabase _db;

                    /**
                     * @brief This is the list of all the clients data
                     *
                     */
                    std::vector<Babel::Client_Data> _client_data;
            };

        } // namespace Babel