//Class Message
#include "../include/Message.h"


//конструктор от текста и уровня
Message::Message(std::string text, Levels level):text(text), message_level(level) {
    time = std::chrono::system_clock::to_time_t(t);
}

//конструктор просто от текста
Message::Message(std::string text):text(text) {
    message_level = informational;
    time = std::chrono::system_clock::to_time_t(t);
}

//методы возвращающие поля
std::string Message::getText() {
    return text;
}

Levels Message::getLevel() {
    return message_level;
}

std::time_t Message::getTime() {
    return time;
}
