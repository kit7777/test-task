//Class Message
#include "../include/Message.h"


//конструктор от текста и уровня
Message::Message(std::string text, Levels level):text(text), message_level(level) {
    now = time(0);
}

//конструктор просто от текста
Message::Message(std::string text):text(text) {
    message_level = informational;
    now = time(0);
}

//методы возвращающие поля
std::string Message::getText() {
    return text;
}

Levels Message::getLevel() {
    return message_level;
}

std::time_t Message::getTime() {
    return now;
}
