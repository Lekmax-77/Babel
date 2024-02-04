/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** main
*/

#include <iostream>
#include <asio.hpp>
#include "MultiClientServer.hpp"
#include "DatabasesSqlite.hpp"
#include <memory>

int Launch_Server(int port)
{
    // Server::SQLiteDatabase db;
    // std::vector<Server::Client> clients = db.getUsers();
    try {
        asio::io_context ioContext;
        std::shared_ptr<Babel::Server::Network::MultiClientServer> server = std::make_shared<Babel::Server::Network::MultiClientServer>(ioContext, port);
    
        server->run();
    } catch (const std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./Babel_Server <port>" << std::endl;
        return 84;
    } else if (atoi(argv[1]) < 0 || atoi(argv[1]) > 65535) {
        std::cerr << "Invalid port" << std::endl;
        return 84;
    } else if (argc  == 2 && std::string(argv[1]) == "-help") {
        std::cout << "USAGE: ./Babel_Server <port>" << std::endl;
        std::cout << "\t<port> is the server port number" << std::endl;
        return 0;
    }

    return Launch_Server(atoi(argv[1]));
    return 0;
}
