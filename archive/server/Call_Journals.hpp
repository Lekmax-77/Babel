/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Call_Journals.hpp
*/
#ifndef CALL_JOURNALS_HPP_
	#define CALL_JOURNALS_HPP_

namespace Babel::Server
{
    class Call_Journals
    {
        public:
            Call_Journals(int id, std::string username, std::string date, std::string duration, bool accepted): _username(username), _date(date), _duration(duration), _accepted(accepted), _id(id)
            {
                ;
            }
            ~Call_Journals() = default;

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

            bool _accepted;

    };

}

#endif /*CALL_JOURNALS_HPP_*/