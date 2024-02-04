/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** ClientHandler
*/

#pragma once
    
#include <memory>
#include <iostream>
#include <vector>
#include <netinet/in.h>
#include <asio.hpp>
#include "../../common/Client.hpp"
#include "MultiClientServer.hpp"
#include <boost/asio/streambuf.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/buffer.hpp>
#include "../../common/Message.hpp"

namespace Babel::Server::Network
        {
            /**
             * @brief This class is the client handler, it will handle all the client's requests
             *
             */
            class MultiClientServer; // Forward declaration

            /**
             * @brief This class is the client handler, it will handle all the client's requests
             *
             */
            class ClientHandler : public std::enable_shared_from_this<ClientHandler>
            {
                public:
                    /**
                     * @brief Construct a new Client Handler object
                     *
                     * @param ioContext is the asio context
                     * @param server is the server
                     */
                    explicit ClientHandler(asio::io_context &ioContext, MultiClientServer &server);

                    /**
                     * @brief a static function that will create a new instance of the client handler
                     * @param ioContext is the asio context
                     * @param server is the server
                     * @return ClientHandler* is the new instance of the client handler
                     */
    	    		static ClientHandler *create_instance(asio::io_context &ioContext, MultiClientServer &server);

                    /**
                     * @brief a static function that will split a string
                     *
                     * @param str is the string to split
                     * @param delim is the delimiter
                     * @return std::vector<std::string> is the vector of strings
                     */
                    static std::vector<std::string> split(const std::string& str, const std::string& delim)
                    {
                        std::vector<std::string> tokens;
                        size_t prev = 0, pos = 0;
                        do
                        {
                            pos = str.find(delim, prev);
                            if (pos == std::string::npos) pos = str.length();
                            std::string token = str.substr(prev, pos-prev);
                            if (!token.empty()) tokens.push_back(token);
                            prev = pos + delim.length();
                        }
                        while (pos < str.length() && prev < str.length());
                        return tokens;
                    }

                    /**
                     * @brief Get the handler object
                     *
                     * @return ClientHandler*
                     */
                    ClientHandler* get_handler();

                    /**
                     * @brief This function will start the client handler
                     *
                     * @param socket is the socket of the client
                     */
                    void start(asio::ip::tcp::socket &socket);

                    /**
                     * @brief This function will disconnect the client
                     *
                     */
                    void disconnect();

                    /**
                     * @brief This function will read the client's request
                     *
                     */
                    void doRead();

                    /**
                     * @brief This function will handle the client's request
                     *
                     * @param err is the error code
                     * @param bytes_transferred is the number of bytes transferred
                     */
                    void ReadHandler(const boost::system::error_code& err, std::size_t bytes_transferred);

                    /**
                     * @brief This function will treat the client's request
                     *
                     * @param msg is the message
                     */
                    void TreatRequest(Babel::BabelProtocol::Message msg);

                    /**
                     * @brief This function will send a message to the client
                     *
                     * @param msg is the message
                     */
                    void doSend(Babel::BabelProtocol::Message msg);

                    /**
                     * @brief This function will handle the client's response
                     *
                     * @param err is the error code
                     * @param bytes_transferred is the number of bytes transferred
                     */
                    void WriteHandler(const boost::system::error_code& err, size_t bytes_transferred);

                    /**
                     * @brief This function will return the asio context
                     *
                     * @return asio::io_context& is the asio context
                     */
                    asio::io_context &get_io_context() const;

                    /**
                     * @brief This function will return the socket
                     *
                     * @return asio::ip::tcp::socket& is the socket
                     */
                    asio::ip::tcp::socket &get_socket();

                    /**
                     * @brief This function will return the server
                     *
                     * @return MultiClientServer* is the server
                     */
                    Babel::Client_Data getClient() const;

                    /**
                     * @brief This function will set the server
                     *
                     * @param server is the server
                     */
                    void setClient(Babel::Client_Data &client);

                private:

                    void LogCmd(BabelProtocol::Message msg);
                    void RegisterCmd(BabelProtocol::Message msg);
                    void CallRequestCmd(BabelProtocol::Message msg);
                    void CallResponseCmd(BabelProtocol::Message msg);
                    void CallEndCmd(BabelProtocol::Message msg);
                    void LogoutCmd(BabelProtocol::Message msg);
                    void DisconnectCmd(BabelProtocol::Message msg);
                protected:
                private:
                    /**
                     * @brief This is the response buffer
                     *
                     */
                    asio::streambuf response_{4096};

                    /**
                     * @brief This is the read buffer
                     *
                     */
                    std::vector<char> _read;

                    /**
                     * @brief This is the message
                     *
                     */
                    Babel::BabelProtocol::Message _message;

                    /**
                     * @brief This is the asio context
                     *
                     */
                    asio::ip::tcp::socket socket_;

                    /**
                     * @brief This is the server
                     *
                     */
                    Babel::Server::Network::MultiClientServer *server_;

                    /**
                     * @brief This is the asio context
                     *
                     */
                    asio::io_context *iocontext_;

                    /**
                     * @brief This is the client
                     *
                     */
                    Babel::Client_Data client_;
                };


        } // namespace Babel