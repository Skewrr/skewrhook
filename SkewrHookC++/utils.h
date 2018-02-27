#pragma once
#include <string>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define RETURN 13
#define BACKSPACE 8

struct COLOURS {
	int black = 0;
	int blue = 1;
	int green = 2;
	int aqua = 3;
	int red = 4;
	int purple = 5;
	int yellow = 6;
	int white = 7;
	int gray = 8;
	int light_blue = 9;
	int light_green = 10;
	int light_aqua = 11;
	int light_red = 12;
	int light_purple = 13;
	int light_yellow = 14;
	int bright_white = 15;
};

COLOURS colours;

using std::cout;
using std::cin;
using std::endl;

std::string passinput();
int menu(std::string *list, int sizeoflist);
int *getConsoleSize();
void showcursor(bool status);
void coloured(std::string text, int colour);