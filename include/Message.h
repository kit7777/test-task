#include <iostream>
#include <cstring>
#include <fstream>
#include <ctime>
#include <chrono>
#include "Levels.h"
#pragma once

//Class Message

class Message {
    std::string text;
    Levels message_level;
    std::time_t now;
        

public:
    Message() = delete;//запрещен, так как запись без текста, кажется бессмысленной
    
    //конструктор просто от текста
    Message(std::string text);

    //конструктор от текста и уровня
    Message(std::string text, Levels level);
    
    //методы возвращающие поля
    std::string getText();
    Levels getLevel();
    std::time_t getTime();

};

