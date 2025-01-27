#include "../include/consApp.h"
//функция для считывания строк из потока
std::string correctInputString() {
    std::string text;
    std::getline(std::cin, text);
    return text;
}
//фуекция считывания целых значений из потока
int correctInputInt() {
    int num = 0;
    while(!((std::cin >> num) && (num < 4))) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректный ввод!\n";
    }
    return num;   

}
//перевод из int в Levels
Levels intToLevel(int num) {
    Levels level = informational;    
    if(num == 0) level = critical;
    if(num == 1) level = important;
    return level; 
}

void showHelp() {
    std::cout << "Использование:\n";
    std::cout << "\t\t<name file>\t<default level>\n";
    std::cout << "\t\tpossible levels:\n";
    std::cout << "\t\t\t[0] - critical\n\t\t\t[1] - important\n\t\t\t[2] - imformational\n";
}

void menu() {
    std::cout << "possible commands:\n";
    std::cout << "\t\tadd - add new message\n\t\texit\ncommand: "<< std::endl;
}
//здесь меняются переменные для создания сообщения в зависимости от ввода
void createMessage(std::string& text, Levels& level) {
    int num = '0';
    std::cout << "Enter text message: ";
    text = correctInputString();
    std::cout << "Possible message level:\t[0] - critical, [1] - important, [2] - informational, [3] - do not enter\n";
    std::cout << "Enter message level: ";
    num = correctInputInt();
    level = intToLevel(num);    
}
//проверка параметров
bool correctLevel(const char* str, Levels& level) {
    int num = std::atoi(str);
    if((num != 0) && (num < 3)) {
        level = intToLevel(num);
        return true;
    }
    if(str[0] == '0') {
        level = intToLevel(0);
        return true;
    }
    return false;
}

bool correctNameFile(const char* str, std::string& name) {
    name = str;
    return true;
}

