//Class Journal
#include "../include/Journal.h"


//конструктор по названию журнала
Journal::Journal(std::string filename):filename(filename){
    def_message_level = informational;//по дефолту все сообщения будут записаны
    std::ofstream out(filename, std::ios::app|std::ios::ate);
    out.close();
}
//конструктор с указанием дефолтного уровня сообщений
Journal::Journal(std::string filename, Levels level):filename(filename), def_message_level(level) {
    std::ofstream out(filename, std::ios::app|std::ios::ate);
    out.close();
}

//метод записи сообщения в журнал
void Journal::addM(Message mess) { 
    if(mess.getLevel()<=def_message_level) {//проверка уровня при записи сообщений
    std::string temptime = "time";
    std::time_t time = mess.getTime();
    temptime = std::ctime(&time);
    temptime.pop_back();
    std::ofstream out(filename, std::ios::app|std::ios::ate);
    out <<mess.getLevel()<<'\t'<<temptime<<'\t'<<mess.getText()<<'\n';
    out.close();
    }
}

//изменение дефолтного уровня сообщений
void Journal::defLevel(Levels level) {
    def_message_level = level;
}
//публичный метод для создания сообщения и добавления его в журнал
void Journal::addMessage(std::string text, Levels level) {
    std::lock_guard<std::mutex> g(m);
    Message m(text, level);
    addM(m);
}
//здесь создание сообщения без указания уровня
void Journal::addMessage(std::string text) {
    Message m(text);
    addM(m);
}
