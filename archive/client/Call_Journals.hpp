/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Call_Journals.hpp
*/
#ifndef CALL_JOURNALS_HPP_
	#define CALL_JOURNALS_HPP_

namespace Babel::Client
{
    class Call_Journals
    {
        public:
            Call_Journals(std::string username, std::string date, std::string duration, bool accepted): _username(username), _date(date), _duration(duration), _accepted(accepted)
            {
                ;
            }
            ~Call_Journals() = default;

            Call_Journals(std::vector<char> data)
            {
                std::memcpy(&_id, data.data(), sizeof(int));
                _username = std::string(data.data() + sizeof(int), data.size() - sizeof(int));
                _date = std::string(data.data() + sizeof(int) + _username.size(), data.size() - sizeof(int) - _username.size());
                _duration = std::string(data.data() + sizeof(int) + _username.size() + _date.size(), data.size() - sizeof(int) - _username.size() - _date.size());
                _accepted = *reinterpret_cast<bool*>(data.data() + sizeof(int) + _username.size() + _date.size() + _duration.size());
            }

            std::vector<chat> serialize() const
            {
                std::vector<char> data;
                data.resize(sizeof(int) + _username.size() + sizeof(int) + _date.size() + sizeof(int) + _duration.size() + sizeof(int));
                std::memcpy(data.data(), &_id, sizeof(int));
                std::memcpy(data.data() + sizeof(int), _username.c_str(), _username.size());
                std::memcpy(data.data() + sizeof(int) + _username.size(), &_date, sizeof(int));
                std::memcpy(data.data() + sizeof(int) + _username.size() + sizeof(int), _date.c_str(), _date.size());
                std::memcpy(data.data() + sizeof(int) + _username.size() + sizeof(int) + _date.size(), &_duration, sizeof(int));
                std::memcpy(data.data() + sizeof(int) + _username.size() + sizeof(int) + _date.size() + sizeof(int), _duration.c_str(), _duration.size());
                std::memcpy(data.data() + sizeof(int) + _username.size() + sizeof(int) + _date.size() + sizeof(int) + _duration.size(), &_accepted, sizeof(bool));
                return data;
            }

            // getters and setters
            std::string getUsername() const
            {
                return _username;
            }

            void setUsername(std::string username)
            {
                _username = username;
            }

            std::string getDate() const
            {
                return _date;
            }

            void setDate(std::string date)
            {
                _date = date;
            }

            std::string getDuration() const
            {
                return _duration;
            }

            void setDuration(std::string duration)
            {
                _duration = duration;
            }

            bool getAccepted() const
            {
                return _accepted;
            }

            void setAccepted(bool accepted)
            {
                _accepted = accepted;
            }
            void setId(int id)
            {
                _id = id;
            }

            int getId() const
            {
                return _id;
            }
        protected:
        private:

            /**
             * @brief The id of the call
             */
            int _id;

            /**
             * @brief The username of the person who called
             */
            std::string _username;

            /**
             * @brief The date of the call
             */
            std::string _date;

            /**
             * @brief The duration of the call
             */
            std::string _duration;

            /**
             * @brief The status of the call
             */
            bool _accepted;

    };

}

#endif /*CALL_JOURNALS_HPP_*/