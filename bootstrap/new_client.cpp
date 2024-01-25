#include <iostream>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::udp;

class UDPClient {
public:
    UDPClient(boost::asio::io_context& io_context, const std::string& server_ip, short server_port)
        : socket_(io_context, udp::endpoint(udp::v4(), 0)), server_endpoint_(boost::asio::ip::address::from_string(server_ip), server_port) {
        startUserInput();
    }

private:
    void startUserInput() {
        std::cout << "Enter a message (or 'exit' to quit): ";

        std::getline(std::cin, user_input_);

        if (user_input_ == "exit") {
            return;  // Exit the program
        }

        sendMessage();
    }

    void sendMessage() {
        socket_.async_send_to(
            boost::asio::buffer(user_input_), server_endpoint_,
            [this](const boost::system::error_code& error, std::size_t /*bytes_sent*/) {
                handleSend(error);
            });
    }

    void handleSend(const boost::system::error_code& error) {
        if (!error) {
            std::cout << "Message sent successfully." << std::endl;
        } else {
            std::cerr << "Error sending message: " << error.message() << std::endl;
        }

        // Continue waiting for user input
        startUserInput();
    }

    udp::socket socket_;
    udp::endpoint server_endpoint_;
    std::string user_input_;
};

int main() {
    try {
        boost::asio::io_context io_context;
        UDPClient client(io_context, "127.0.0.1", 12345);  // Replace with your server's IP and port
        io_context.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
