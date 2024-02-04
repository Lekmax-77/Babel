/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** main
*/

#include <iostream>
#include <asio.hpp>
#include "NetworkManager.hpp"
#include <memory>
#include "Cli.hpp"

int Launch_Client(int ac, char **av)
{
    (void)ac;
    Babel::Client::Cli client(av[1], atoi(av[2]));
    try {
        client.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    return 0;

}

int main(int ac, char **av) {
    if (ac != 3) {
        std::cerr << "Usage: ./Babel_Client <host> <port>" << std::endl;
        return 84;
    }

    int port = atoi(av[2]);
    if (port < 0 || port > 65535) {
        std::cerr << "Invalid port" << std::endl;
        return 84;
    }

    return Launch_Client(ac, av);
}
