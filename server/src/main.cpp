/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** main
*/

#include <iostream>
#include <vector>
#include <array>
#include <boost/asio.hpp>

const int max_length = 1024;

class Server
{
    public:
        Server(boost::asio::io_context& io_context, short port)
            : socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)) {
            startReceive();
        }

    private:
        void startReceive() {
            socket_.async_receive_from(
                boost::asio::buffer(data_, max_length), sender_endpoint_,
                [this](const boost::system::error_code& error, std::size_t bytes_received) {
                    handleReceive(error, bytes_received);
                });
        }

        void handleReceive(const boost::system::error_code& error, std::size_t bytes_received) {
            if (!error) {
                processMessage(bytes_received);
                startReceive();
            }
        }

        void processMessage(std::size_t length) {
            // Assume that the received data is a simple binary protocol.
            // You should implement your own protocol based on your application needs.
            // For example, you might want to define a specific structure for your messages.

            // This is just a simple example, assuming the data is an integer.
            if (length == sizeof(int)) {
                int receivedValue;
                std::memcpy(&receivedValue, data_.data(), sizeof(int));

                // Process the received value (you can replace this with your own logic).
                std::cout << "Received: " << receivedValue << std::endl;
            }
        }

        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint sender_endpoint_;
        std::array<char, max_length> data_;
};


int main(int ac, char **av) {

    if (ac != 2) {
        std::cerr << "Usage : ./babel_server <port>" << std::endl;
        return 1;
    } else if (av[1] == "-h" || av[1] == "--help") {
        std::cout << "Usage : ./babel_server <port>" << std::endl;
        return 0;
    }
    
    std::cout << "Server started on port " << av[1] << std::endl;
    try {
        
        boost::asio::io_context io_context;
        Server server(io_context, std::stoi(av[1])); 
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

