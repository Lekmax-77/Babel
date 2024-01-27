/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_
    #include <iostream>
    #include <vector>
    #include "Contacts.hpp"

namespace Server {
    class Client {
        public:
            Client() : _id(0) {}
            Client(const std::string &username, const std::string &password, std::size_t id)
            {
                _username = username;
                _password = password;
                _id = id;
            }

            const std::string &getUsername() const
            {
                return _username;
            }

            void setUsername(const std::string &username)
            {
                _username = username;
            }

            const std::string &getPassword() const
            {
                return _password;
            }

            void setPassword(const std::string &password)
            {
                _password = password;
            }

            std::size_t getId() const
            {
                return _id;
            }

            void setId(std::size_t id)
            {
                _id = id;
            }

            bool addContact(const Contacts &contact)
            {
                for (auto &i : _contacts) {
                    if (i.getId() == contact.getId())
                        return false;
                }
                _contacts.push_back(contact);
                return true;
            }

            bool addContact(const std::string &name, int id, int status=0)
            {
                for (auto &i : _contacts) {
                    if (i.getId() == id)
                        return false;
                }
                _contacts.push_back(Contacts(name, id, status));
                return true;
            }

            bool removeContact(const Contacts &contact)
            {
                for (auto &i : _contacts) {
                    if (i.getId() == contact.getId()) {
                        _contacts.erase(_contacts.begin() + i.getId());
                        return true;
                    }
                }
                return false;
            }

            bool removeContact(int id) {
                for (auto it = _contacts.begin(); it != _contacts.end(); ++it) {
                    if (it->getId() == id) {
                        _contacts.erase(it);
                        return true;
                    }
                }
                return false;
            }

            std::vector<Contacts> &getContacts()
            {
                return _contacts;
            }

            ~Client() = default;

        protected:
        private:
            std::string _username;
            std::string _password;
            std::size_t _id;
            std::vector<Contacts> _contacts;
    };
}

#endif /* !CLIENT_HPP_ */
