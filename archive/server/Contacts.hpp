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
    namespace Server
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
    } // namespace Server
} // namespace Babel
