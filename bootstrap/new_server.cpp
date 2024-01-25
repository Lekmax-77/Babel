#include <iostream>
#include <boost/asio.hpp>
#include <array>
#include <iomanip>  

using boost::asio::ip::udp;

class UDPServer {
public:
    UDPServer(boost::asio::io_context& io_context, short port)
        : socket_(io_context, udp::endpoint(udp::v4(), port)) {
        startReceive();
    }

private:
    void startReceive() {
        socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            [this](const boost::system::error_code& error, std::size_t bytes_transferred) {
                handleReceive(error, bytes_transferred);
            });
    }

    void handleReceive(const boost::system::error_code& error, std::size_t bytes_transferred) {
        if (!error) {
            // Process the received data
            processMessage(bytes_transferred);

            // Continue listening for incoming messages
            startReceive();
        }
    }

    void processMessage(std::size_t length) {
        // Assuming the received data is a binary message
        std::cout << "Received message from " << remote_endpoint_ << ": ";
        for (std::size_t i = 0; i < length; ++i) {
            std::cout << recv_buffer_[i];
        }
        std::cout << std::endl;
        for (std::size_t i = 0; i < length; ++i) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(recv_buffer_[i]);
        }
        std::cout << std::dec << std::endl;
    }

    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    std::array<char, 1024> recv_buffer_;
};

int main() {
    try {
        boost::asio::io_context io_context;
        UDPServer server(io_context, 12345);  // Replace 12345 with your desired port number
        io_context.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
