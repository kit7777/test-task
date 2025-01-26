#include <iostream>
#include <thread>
#include "../include/Journal.h"
#include "../include/Message.h"
#include "../include/consApp.h"

int main(int argc, char* argv[]) {
    std::string nameFile = "newJournal";//переменные для создания журнала
    Levels level = informational;
    if(argc != 3) { //провека на количество параметров
        showHelp();
        return 0;
    }//проверка на корректность введенных параметров
    if(!(correctLevel(argv[2], level) && correctNameFile(argv[1], nameFile))) {
        showHelp();
        return 0;
    }
    Journal newJournal(nameFile, level);//создается журнал
    std::string textMessage = "-";//переменные для создания сообщения
    Levels levelMessage = informational;
    bool Exit = false;
    std::string cmd = "exit";
    while(!Exit) {
        menu();
        std::getline(std::cin, cmd);
        if(cmd == "add") {
            createMessage(textMessage, levelMessage);//изменяются значения переменных для сообщ.
            std::thread message([&](){newJournal.addMessage(textMessage, levelMessage);});
            message.detach();//метод добавления сообщения в журнал в отдельный поток             
        }
        if(cmd == "exit") Exit = true;
    }

}
