#include <conio.h>
#include <iostream>
#include <string>
#include "utils.h"

using std::cout;
using std::endl;

std::string passinput() {
	int c;
	std::string pass;
	while (1) {
		c = _getch();
		if (c == 8) { pass = pass.substr(0, pass.length() - 1); }
		else if (c == 13) { break; }
		else { pass += c; }
	}
	return pass;
}