/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Cli.hpp
*/

#pragma once

#include <iostream>
#include <string>
// #include "Contacts.hpp"
#include <vector>
// #include "Call_Journals.hpp"
#include <unordered_map>
#include <functional>
#include <memory>
#include "../../common/Message.hpp"
#include "../../common/Client.hpp"
#include "NetworkManager.hpp"


namespace Babel::Client
{
    class INetworkManager; // Forward declaration


    class Cli
    {
        public:
            Cli(const std::string& ip, int port);

            ~Cli();

            void run();

            void readUserInput(asio::io_context &io);

            void TreatRequest(const Babel::BabelProtocol::Message& msg);

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

        private:
            void processCmd(const std::string& cmd)
            {
                std::vector<std::string> temp = Cli::split(cmd, " ");
                auto commandIter = commandMap.find(temp[0]);


                if (commandIter != commandMap.end()) {
                    (this->*commandIter->second)(cmd);
                } else {
                    unknownCommand(cmd);
                }
            }

        private:

            void helpCommand(const std::string& cmd)
            {
                if (cmd != "") {
                    std::cout <<  std::endl;
                    std::cout << "Usage: /command [arguments]" << std::endl;
                }
                std::cout <<  std::endl;
                std::cout << "Commands:" << std::endl;
                std::cout << "\t/help                                   Afficher l'aide générale" << std::endl;
                std::cout << "\t/login <username> <password>            Se connecter avec le nom d'utilisateur et le mot de passe" << std::endl;
                std::cout << "\t/register <username> <password>         S'enregistrer avec le nom d'utilisateur et le mot de passe" << std::endl;
                std::cout << "\t/logout                                 Se déconnecter" << std::endl;
                std::cout << "\t/users                                  Afficher la liste des utilisateurs" << std::endl;
                // std::cout << "\t/add_contact <username>                 Ajouter un contact" << std::endl;
                // std::cout << "\t/del_contact <username>                 Supprimer un contact" << std::endl;
                // std::cout << "\t/accept_contact <username>              Accepter un contact" << std::endl;
                // std::cout << "\t/contacts                               Afficher la liste des contacts" << std::endl;
                // std::cout << "\t/call_journals                          Afficher les journaux des appels" << std::endl;
                std::cout << "\t/call <username>                        Appeler un contact" << std::endl;
                std::cout << "\t/accept_call <username>                 Accepter un appel" << std::endl;
                std::cout << "\t/reject_call <username>                 Rejeter un appel" << std::endl;
                std::cout << "\t/status {busy, online, offline}         Définir votre statut" << std::endl;
                std::cout <<  std::endl;
                std::cout << "\tUse /help <command> for more information on a specific command." << std::endl;
                std::cout <<  std::endl;
            }

            void unknownCommand(const std::string& cmd)
            {
                std::cout << "Unknown command: " << cmd << std::endl;
                this->helpCommand("");
            }


            void loginCommand(const std::string& cmd);

            void logoutCommand(const std::string& cmd);

            void RegisterCommand(const std::string& cmd);

            void statusCommand(const std::string& cmd);

            void callCommand(const std::string& cmd);

            void acceptCallCommand(const std::string& cmd);

            void rejectCallCommand(const std::string& cmd);

            void userCommand(const std::string& cmd);

        /*
        void addContactCommand(const std::string& cmd);

        void delContactCommand(const std::string& cmd);

        void acceptContactCommand(const std::string& cmd);

        void contactsCommand(const std::string& cmd)
        {
            (void)cmd;
            if (this->_contacts.empty()) {
                std::cout << "No contacts" << std::endl;
            } else {
                std::cout << "Contacts:" << std::endl;
                for (const auto& contact : this->_contacts) {
                    std::cout << "username: " << contact.getUsername()
                              << " id: " << contact.getId()
                              << " status: " << (contact.getStatus() == 1 ? "online" : (contact.getStatus() == 2 ? "busy" : "offline"))
                              << std::endl;
                }
            }
        }

        void callJournalsCommand(const std::string& cmd)
        {
            (void)cmd;
            if (this->_callJournals.empty()) {
                std::cout << "No call journals" << std::endl;
            } else {
                std::cout << "Call journals:" << std::endl;
                for (const auto& callJournal : this->_callJournals) {
                    std::cout << "username: " << callJournal.getUsername()
                              << " date: " << callJournal.getDate()
                              << " duration: " << callJournal.getDuration()
                              << " status: " << (callJournal.getAccepted() == true ? "accepted" : "rejected")
                              << std::endl;
                }
            }
        }
        */

        public:
            void setIp(const std::string& ip)
            {
                _ip = ip;
            }

            std::string getIp() const
            {
                return _ip;
            }

            void setPort(int port)
            {
                _port = port;
            }

            int getPort() const
            {
                return _port;
            }

            void setConnected(bool connected)
            {
                _connected = connected;
            }

            bool getConnected() const
            {
                return _connected;
            }

            void setUsername(const std::string& username)
            {
                _username = username;
            }

            std::string getUsername() const
            {
                return _username;
            }

            void setPassword(const std::string& password)
            {
                _password = password;
            }

            std::string getPassword() const
            {
                return _password;
            }

            void setStatus(const std::string& status)
            {
                _status = status;
            }

            std::string getStatus() const
            {
                return _status;
            }

            void setId(short id)
            {
                _id = id;
            }

            short getId() const
            {
                return _id;
            }

            void setCliData(const Babel::Client_Data& data)
            {
                _data = data;
            }

            Babel::Client_Data getCliData() const
            {
                return _data;
            }


        private:
            std::shared_ptr<Babel::Client::INetworkManager> _networkManager;
            std::string _ip;
            int _port;
            bool _connected;
            std::string _username;
            std::string _password;
            std::string _status;
            short _id;

            Babel::Client_Data _data;


            const std::unordered_map<std::string, void (Babel::Client::Cli::*)(const std::string&)> commandMap = {
                {"/help", &Cli::helpCommand},
                {"/login", &Cli::loginCommand},
                {"/logout", &Cli::logoutCommand},
                {"/register", &Cli::RegisterCommand},
                //{"/add_contact", &Cli::addContactCommand},
                //{"/del_contact", &Cli::delContactCommand},
                //{"/accept_contact", &Cli::acceptContactCommand},
                {"/users", &Cli::userCommand},
                //{"/call_journals", &Cli::callJournalsCommand},
                {"/call", &Cli::callCommand},
                {"/accept_call", &Cli::acceptCallCommand},
                {"/reject_call", &Cli::rejectCallCommand},
                {"/status", &Cli::statusCommand}
        };
    };

}
