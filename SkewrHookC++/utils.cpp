#include <conio.h>
#include <iostream>
#include <windows.h>
#include "utils.h"

COLOURS colours;

std::string passinput() {
	int c;
	std::string pass;
	while (1) {
		c = _getch();
		if (c == BACKSPACE) { pass = pass.substr(0, pass.length() - 1); }
		else if (c == RETURN) { break; }
		else { pass += c; }
	}
	return pass;
}

int *getConsoleSize() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int size[2] = { rows,columns };
	return size;
}

void showcursor(bool status)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = status;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void coloured(std::string text, int colour) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	cout << text;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int menu(std::string *list, int sizeoflist) {
	int pos = 0;
	int key = 0;
	while (1) {
		showcursor(FALSE);
		system("cls");
		for (int i = 0; i < (getConsoleSize()[0] / 2) - sizeoflist - (pos * 2); i++)
			cout << "\n";
		if (pos > sizeoflist - 1) { pos = 0; }
		if (pos < 0) { pos = sizeoflist - 1; }
		for (int i = 0; i < sizeoflist; i++) {
			for (int j = 0; j < (getConsoleSize()[1] / 2) - ((int)list[i].length()  / 2); j++)
				cout << " ";
			if (i == pos) {
				coloured("-> " + list[i] + "\n\n", colours.light_purple);
			}
			else {
				cout << "   " << list[i] << "\n\n";
			}
		}

		key = 0;
		switch ((key = _getch())) {
		case KEY_UP:
			pos--;
			break;
		case KEY_DOWN:
			pos++;
			break;
		case RETURN:
			system("cls");
			showcursor(TRUE);
			return pos;
		}
	}
}