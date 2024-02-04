/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Cli.cpp
*/

#include "../includes/Cli.hpp"
#include "../includes/NetworkManager.hpp"



namespace Babel::Client
{

    Cli::Cli(const std::string &ip, int port) : _ip(ip), _port(port), _connected(false)/*, _contacts(), _callJournals()*/
    {
        _username = "guest";
        _password = "guest";
        _status = "offline";
        _id = 0;
        _networkManager = std::make_shared<Babel::Client::AsioNetworkManager>(*this, _ip, _port);
    }

    Cli::~Cli()
    {
        ;
    }

    void Cli::run()
    {
        _networkManager->connect();
        asio::io_context &io = _networkManager->getIoContext();
        std::cout << "Enter command (or 'exit' to quit): " << std::endl;
        asio::io_context::strand strand(io);

        io.post(strand.wrap([this, &io]()
            {
                readUserInput(io);
            }));
        io.run();

    }

    void Cli::readUserInput(asio::io_context &io)
    {
        std::cout << "&> ";
        std::string userCmd;
        std::getline(std::cin, userCmd);

        if (userCmd == "exit")
            exit(0);
        if (!userCmd.empty()) {
            std::cout << "You entered: " << userCmd << std::endl;
            io.post([this, userCmd]() {
                processCmd(userCmd);
            });
        }
        io.post([this, &io]() {
            readUserInput(io);
        });
    }

    void Cli::TreatRequest(const Babel::BabelProtocol::Message& msg)
    {
        int type = msg.getType();
        (void)msg;
        std::cout << "TreatRequest:" << type << std::endl;
        //TODO: Treat the request

    }

    void Cli::loginCommand(const std::string& cmd)
    {
        std::vector<std::string> temp = Cli::split(cmd, " ");
        std::string username = temp[1];
        std::string password = temp[2];
        std::cout << "Login with username: " << username << " and password: " << password << std::endl;
        _networkManager->doSend(Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::LOG, std::string(username+":"+password)));
        //TODO: wait login response
        //TODO: after update all info
    }

    void Cli::logoutCommand(const std::string& cmd)
    {
        (void)cmd;
        if (!_connected) {
            std::cout << "You are not connected" << std::endl;
            return;
        }
        _networkManager->doSend(Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::LOG_OUT));
        std::cout << "Logout!" << std::endl;
        this->_connected = false;
        _username = "guest";
        _password = "guest";
        _status = "offline";
        _id = 0;
    }

    void Cli::RegisterCommand(const std::string& cmd)
    {
        std::vector<std::string> temp = Cli::split(cmd, " ");
        (void)cmd;
        if (_connected) {
            std::cout << "You are already connected" << std::endl;
            return;
        } else {
            std::cout << "Register with username: " << temp[1] << " and password: " << temp[2] << std::endl;
        }
        _networkManager->doSend(Babel::BabelProtocol::Message(Babel::BabelProtocol::Message::MessageType::REGISTER, std::string(temp[1]+":"+temp[2])));
        //TODO: wait register response
        //TODO: after update all info
    }

    void Cli::statusCommand(const std::string& cmd)
    {
        if (!_connected)
            std::cout << "You are not connected" << std::endl;
        (void)cmd;
        std::cout << "Current status: " << _status << std::endl;
    }


    void Cli::callCommand(const std::string& cmd)
    {
        if (!_connected)
            std::cout << "You are not connected" << std::endl;
        //TODO: update call journal
        (void)cmd;
        std::cout << "Call command" << std::endl;
    }

    void Cli::acceptCallCommand(const std::string& cmd)
    {
        if (!_connected)
            std::cout << "You are not connected" << std::endl;
        //TODO: update call journal
        (void)cmd;
        std::cout << "Accept call command" << std::endl;
    }

    void Cli::rejectCallCommand(const std::string& cmd)
    {
        if (!_connected)
            std::cout << "You are not connected" << std::endl;
        //TODO: update call journal
        (void)cmd;
        std::cout << "Reject call command" << std::endl;
    }

    void Cli::userCommand(const std::string& cmd)
    {
        (void)cmd;
        //TODO: print all users
    }
}