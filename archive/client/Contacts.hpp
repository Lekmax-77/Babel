/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Contacts
*/

#pragma once

#include <iostream>

namespace Babel
{
    namespace Client
    {
        /**
         * @brief This class is the contacts class
         * 
         */
        class Contacts {
        public:
            /**
             * @brief Construct a new Contacts object
             * 
             * @param name is the name of the contact
             * @param id is the id of the contact
             * @param status is the status of the contact
             */
            Contacts(const std::string &name, std::size_t id, short status)
            {
                _name = name;
                _id = id;
                _status = status;
            }

            /**
             * @brief Construct a new Contacts object
             * 
             */
            Contacts() = default;

            /**
             * @brief Destroy the Contacts object
             * 
             */
            ~Contacts() = default;

            Contacts(std::vector<char> data)
            {
                std::memcpy(&_id, data.data(), sizeof(std::size_t));
                std::memcpy(&_status, data.data() + sizeof(std::size_t), sizeof(short));
                _name = std::string(data.data() + sizeof(std::size_t) + sizeof(short), data.size() - sizeof(std::size_t) - sizeof(short));
            }

            std::vector<char> serialize() const
            {
                std::vector<char> data;
                data.resize(sizeof(std::size_t) + sizeof(short) + _name.size());
                std::memcpy(data.data(), &_id, sizeof(std::size_t));
                std::memcpy(data.data() + sizeof(std::size_t), &_status, sizeof(short));
                std::memcpy(data.data() + sizeof(std::size_t) + sizeof(short), _name.c_str(), _name.size());
                return data;
            }


            // getters and setters
            /**
             * @brief Get the Id object
             * 
             * @return int 
             */
            int getId() const
            {
                return _id;
            }

            /**
             * @brief Set the Id object
             * 
             * @param id is the id of the contact
             */
            void setId(int id)
            {
                _id = id;
            }

            /**
             * @brief Get the Status object
             * 
             * @return int 
             */
            int getStatus() const
            {
                return _status;
            }

            /**
             * @brief Set the Status object
             * 
             * @param status is the status of the contact
             */
            void setStatus(int status)
            {
                _status = status;
            }

            /**
             * @brief Get the Name object
             * 
             * @return std::string 
             */
            std::string getUsername() const
            {
                return _name;
            }

            /**
             * @brief Set the Name object
             * 
             * @param name is the name of the contact
             */
            void setUsername(const std::string &name)
            {
                _name = name;
            }

        protected:
        private:
            /**
             * @brief This is the name of the contact
             * 
             */
            std::string _name;

            /**
             * @brief This is the id of the contact
             * 
             */
            std::size_t _id;

            /**
             * @brief This is the status of the contact
             * 
             */
            short _status; // 0 = offline, 1 = online, 2 = in call
        };
    } // namespace Client
} // namespace Babel
