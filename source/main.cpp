#include <iostream>
#include "../include/Journal.h"
#include "../include/Message.h"
#include "../include/consApp.h"

int main(int argc, char* argv[]) {
    std::string nameFile = "newJournal";
    Levels level = informational;
    if(argc != 3) { //провека на количество параметров
        showHelp();
        return 0;
    }//проверка на корректность введенных параметров
    if(!(correctLevel(argv[2], level) && correctNameFile(argv[1], nameFile))) {
        showHelp();
        return 0;
    }
    Journal newJournal(nameFile, level);
    std::string textMessage = "-";
    Levels levelMessage = informational;
    bool Exit = false;
    std::string cmd = "exit";
    while(!Exit) {
        menu();
        std::getline(std::cin, cmd);
        if(cmd == "add") {
            createMessage(textMessage, levelMessage);            
        }
        if(cmd == "exit") Exit = true;
    }
    std::cout << "Text: "<<textMessage<<'\n'<<"level: "<<levelMessage<<'\n';

    

}
