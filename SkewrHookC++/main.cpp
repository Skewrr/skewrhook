#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include "utils.h"


int main()
{
	std::string uname;
	std::string passw;
	std::string list[4] = { "Rainbow","Option 2","Option 3","Quit" };

	coloured("--- SKEWRHOOK ---\n\n", colours.light_red);
	cout << "Username: ";
	cin >> uname;
	cout << "Password: ";
	passw = passinput();
	cout << endl;

	if (uname == "skewr" && passw == "clout") {

		switch (menu(list, 4)) {
		case 0:
			cout << "rainbow text";
			char hex[20];
			while(1)
				for (int i = 0; i < 16; i++) {
					sprintf_s(hex, "color %x", i * 16);
					system(hex);
					if (GetAsyncKeyState(VK_SPACE)) { break; }
					if (GetAsyncKeyState(VK_ESCAPE)) { system("color f && cls"); return main(); }
					Sleep(10);
				}

		case 4:
			exit(0);
		}
	}
	return 0;

}