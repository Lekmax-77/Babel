/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Contacts
*/

#ifndef CONTACTS_HPP_
    #define CONTACTS_HPP_
    #include <iostream>

namespace Client {

class Contacts {
    public:
        Contacts(std::string name, int id, int status)
        {
            _name = name;
            _id = id;
            _status = status;
        }

        Contacts() = default;
        ~Contacts() = default;

        int getId() const
        {
            return _id;
        }

        void setId(int id)
        {
            _id = id;
        }

        int getStatus() const
        {
            return _status;
        }

        void setStatus(int status)
        {
            _status = status;
        }

        std::string getName() const
        {
            return _name;
        }

        void setName(std::string name)
        {
            _name = name;
        }

    protected:
    private:
        std::string _name;
        int _id;
        int _status;
};
}

#endif /* !CONTACTS_HPP_ */
