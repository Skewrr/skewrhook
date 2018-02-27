#pragma once
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define RETURN 13
#define BACKSPACE 8

using std::cout;
using std::cin;
using std::endl;

std::string passinput();
int menu(std::string *list, int sizeoflist);
int *getConsoleSize();
void showcursor(bool status);