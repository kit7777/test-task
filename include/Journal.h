#include <cstring>
#include <fstream>
#include <cstring>
#include <chrono>
#include <ctime>
#include <mutex>
#include "Levels.h"
#include "Message.h"
#pragma once

//Class Journal
class Journal {
    std::string filename;
    Levels def_message_level;
    std::mutex m;
  
    void addM(Message mess);
public:
    Journal () = delete;
    //конструктор создания журнала с дефолнтым уровнем важности
    Journal(std::string filename);
    
    //конструктор с указанием дефолного значения важности
    Journal(std::string filename, Levels level);

    //метод записи сообщения в журнал
    void addMessage(std::string text, Levels level);
    void addMessage(std::string text);

    //изменение дефолтного уровня
    void defLevel(Levels level);
};
