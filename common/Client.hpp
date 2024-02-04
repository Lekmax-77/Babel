/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Client
*/

#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace Babel
{
    /**
     * @brief Class to store client data
     *
     */
    class Client_Data {
        public:
            /**
             * @brief Construct a new Client_Data object
             *
             */
            Client_Data() : _username(""), _password(""), _id(0), _ipAddress("127.0.0.1"), _port(0) {}

            /**
             * @brief Construct a new Client_Data object
             *
             * @param client is the client to copy
             */
            Client_Data(const Client_Data &client)
            {
                _username = client._username;
                _password = client._password;
                _ipAddress = client._ipAddress;
                _port = client._port;
                _id = client._id;
            }

            /**
             * @brief Construct a new Client_Data object
             *
             * @param username is the username of the client
             * @param password is the password of the client
             * @param id id of the client
             */
            Client_Data(const std::string &username, const std::string &password, std::size_t id)
            {
                _username = username;
                _password = password;
                _id = id;
            }

            /**
             * @brief Overload of the = operator
             *
             * @param client is the client to copy
             * @return Client_Data& is the new client
             */
            Client_Data &operator=(const Client_Data &client)
            {
                _username = client._username;
                _password = client._password;
                _id = client._id;
                return *this;
            }

            /**
             * @brief Destroy the Client_Data object
             *
             */
            ~Client_Data() = default;

            /**
             * @brief Construct a new Client_Data object
             *
             * @param data is the data to deserialize
             */
            Client_Data(std::vector<char> data)
            {
                deserialize(data);
            }

            /**
             * @brief Serialize the object
             *
             * @return std::vector<char> is the serialized object
             */
            std::vector<char> serialize() const
            {
                std::vector<char> data;

                for (char c : _username)
                    data.push_back(c);
                data.push_back('\0');

                for (char c : _password)
                    data.push_back(c);
                data.push_back('\0');

                // Serialize _id
                data.push_back(static_cast<char>(_id & 0xFF));
                data.push_back(static_cast<char>((_id >> 8) & 0xFF));
                data.push_back(static_cast<char>((_id >> 16) & 0xFF));
                data.push_back(static_cast<char>((_id >> 24) & 0xFF));
                return data;
            }

            /**
             * @brief Get the Username object
             * @return std::string is the username
             */
            std::string getUsername() const
            {
                return _username;
            }

            /**
             * @brief Set the Username object
             *
             * @param username is the new username
             */
            void setUsername(const std::string &username)
            {
                _username = username;
            }

            /**
             * @brief Get the Password object
             *
             * @return std::string is the password
             */
            std::string getPassword() const
            {
                return _password;
            }

            /**
             * @brief Set the Password object
             *
             * @param password is the new password
             */
            void setPassword(const std::string &password)
            {
                _password = password;
            }

            /**
             * @brief Get the Id object
             *
             * @return std::size_t is the id
             */
            std::size_t getId() const
            {
                return _id;
            }

            /**
             * @brief Set the Id object
             *
             * @param id is the new id
             */
            void setId(std::size_t id)
            {
                _id = id;
            }

            /**
             * @brief Get the Status object
             *
             * @return short is the status
             */
            std::string getStatus() const
            {
                return status;
            }

            /**
             * @brief Set the Status object
             *
             * @param status is the new status
             */
            void setStatus(std::string status)
            {
                this->status = status;
            }

            /**
             * @brief Get the Ip Address object
             *
             * @return std::string is the ip address
             */
            std::string getIpAddress() const
            {
                return _ipAddress;
            }

            /**
             * @brief Set the Ip Address object
             *
             * @param ipAddress is the new ip address
             */
            void setIpAddress(const std::string& ipAddress)
            {
                _ipAddress = ipAddress;
            }

            /**
             * @brief Get the Port object
             *
             * @return int is the port
             */
            int getPort() const
            {
                return _port;
            }

            /**
             * @brief Set the Port object
             *
             * @param port is the new port
             */
            void setPort(int port)
            {
                _port = port;
            }

        private:
            /**
             * @brief Ip address of the client
             *
             */
            std::string _ipAddress;

            /**
             * @brief Port of the client
             *
             */
            int _port;

            /**
             * @brief Deserialize the object
             *
             * @param data is the data to deserialize
             */
            void deserialize(const std::vector<char> &data)
            {
                _username.clear();
                _password.clear();
                _id = 0;

                std::size_t index = 0;
                while (data[index] != '\0') {
                    _username.push_back(data[index]);
                    ++index;
                }
                ++index;


                while (data[index] != '\0') {
                    _password.push_back(data[index]);
                    ++index;
                }
                ++index;

                _id = static_cast<std::size_t>(data[index])
                      | (static_cast<std::size_t>(data[index + 1]) << 8)
                      | (static_cast<std::size_t>(data[index + 2]) << 16)
                      | (static_cast<std::size_t>(data[index + 3]) << 24);
            }

        protected:
        private:
            /**
             * @brief Username of the client
             *
             */
            std::string _username;

            /**
             * @brief Password of the client
             *
             */
            std::string _password;

            /**
             * @brief Id of the client
             *
             */
            std::size_t _id;

            /**
             * @brief Status of the client
             *
             */
            std::string status; // offline, online, busy
    };
}
