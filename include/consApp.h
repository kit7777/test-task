#include "Journal.h"
#include <limits>
#include <cstdlib>
#pragma once

std::string correctInputString();
int correctInputInt(); 
void addMessage(Journal& journal, std::string& text, Levels& level);

Levels intToLevel(int num);

void showHelp();
void menu();

bool correctNameFile(const char* str, std::string& fileName);
bool correctLevel(const char* str, Levels& level);


void createMessage(std::string& text_Message, Levels& level_message);
