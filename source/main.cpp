#include <iostream>
#include "../include/Journal.h"
#include "../include/Message.h"
//#include ""

int main() {
    std::string s ="uppps..."; 
    Journal News("HELLO.txt", critical);
    News.addMessage("This is critical note!", critical);
    News.addMessage("This is important note", important);

}
