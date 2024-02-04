/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Message.hpp
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_
#include <string>
#include <vector>
#include <iostream>

namespace Babel::BabelProtocol
{
    /**
     * Class representing a message
     */
    class Message
    {
    public:

        /**
         * Enum representing the type of the message
         */
        enum MessageType {
            Nothing = 0,
            LOG_ACK = 1,            // SERVER -> CLIENT

            REGISTER,               // CLIENT -> SERVER
            REGISTER_LOG,           // SERVER -> CLIENT
            ERROR_REGISTER,         // SERVER -> CLIENT

            LOG,                    // CLIENT -> SERVER
            LOG_OUT,                // CLIENT -> SERVER
            ERROR_LOG,              // SERVER -> CLIENT
            LOG_DATA,               // SERVER -> CLIENT

            CALL_REQUEST,           // CLIENT -> SERVER or SERVER -> CLIENT
            ERROR_CALL_REQUEST,      // SERVER -> CLIENT

            CALLING,                // CLIENT -> SERVER
            CALL_RESPONSE,          // SERVER -> CLIENT or CLIENT -> SERVER
            CALL_ACCEPTED,          // SERVER -> CLIENT
            CALL_REJECTED,          // SERVER -> CLIENT
            CALL_END,               // CLIENT -> SERVER or SERVER -> CLIENT or CLIENT -> CLIENT
            AUDIO_DATA,             // CLIENT -> CLIENT

            /*CONTACTS,        // SERVER -> CLIENT
            CALL_JOURNALS,    // SERVER -> CLIENT
            ADD_CONTACT,            // CLIENT -> SERVER
            REMOVE_CONTACT,         // CLIENT -> SERVER
            CONTACT_REQUEST,        // CLIENT -> SERVER or SERVER -> CLIENT
            CONTACT_RESPONSE,       // SERVER -> CLIENT or CLIENT -> SERVER
            CONTACT_ACCEPTED,       // SERVER -> CLIENT*/

            DISCONNECT              // CLIENT -> SERVER or SERVER -> CLIENT
        };

        /**
         * Constructor
         * @param type Type of the message
         * @param data Data of the message
         */
        Message(MessageType type, std::string data)
        {
            _type = type;
            _data = data;
        }

        /**
         * Constructor
         * @param type Type of the message
         */
        explicit Message(MessageType type)
        {
            _type = type;
            _data = "";
        }

        /**
         * Default constructor
         */
        Message() {_data = ""; _type = MessageType::Nothing;}

        /**
         * Deserialize the message
         * @param binaryData Serialized message
         */
        explicit Message(const std::vector<char> binaryData)
        {
            if (binaryData.size() < sizeof(MessageType) + sizeof(uint32_t)) {
                throw std::runtime_error("Invalid message format");
            }

            _type = *reinterpret_cast<const MessageType*>(&binaryData[0]);
            uint32_t dataSize = *reinterpret_cast<const uint32_t*>(&binaryData[sizeof(MessageType)]);

            if (binaryData.size() < sizeof(MessageType) + sizeof(uint32_t) + dataSize) {
                throw std::runtime_error("Invalid message format");
            }

            _data.assign(&binaryData[sizeof(MessageType) + sizeof(uint32_t)], dataSize);
        }

        /**
         * Serialize the message
         * @return Serialized message
         */
        std::vector<char> serialize() const
        {
            std::vector<char> binaryData(sizeof(MessageType) + sizeof(uint32_t) + _data.size());
            *reinterpret_cast<MessageType*>(&binaryData[0]) = _type;
            *reinterpret_cast<uint32_t*>(&binaryData[sizeof(MessageType)]) = static_cast<uint32_t>(_data.size());
            if (!_data.empty()) {
                std::copy(_data.begin(), _data.end(), &binaryData[sizeof(MessageType) + sizeof(uint32_t)]);
            }
            return binaryData;
        }

        /**
         * Get the type of the message
         * @return Type of the message
         */
        MessageType getType() const { return _type; }

        /**
         * Set the type of the message
         * @param type Type to set
         */
        void setType(MessageType type) { this->_type = type; }

        /**
         * Get the data of the message
         * @return Data of the message
         */
        const std::string& getData() const { return _data; }

        /**
         * Set the data of the message
         * @param data Data to set
         */
        void setData(const std::string& data) { this->_data = data; }

        /**
         * Clear the message
         */
        void clear() { _data.clear(); _type = MessageType::Nothing; }

    private:
        /**
         * Type of the message
         */
        MessageType _type;

        /**
         * Data of the message
         */
        std::string _data;
    };
}


#endif /*MESSAGE_HPP_*/