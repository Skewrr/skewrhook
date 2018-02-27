#include <conio.h>
#include <iostream>
#include <string>
#include "utils.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	std::string uname;
	std::string passw;

	cout << "--- SKEWRHOOK ---\n\n";
	cout << "Username: ";
	cin >> uname;
	cout << "Password: ";
	passw = passinput();
	cout << endl;
	
	if (uname == "skewr" && passw == "clout") {
		cout << "HEY GUYS COMEDYSHORTSGAMER HERE" << endl;
	}
	
	system("pause");
	return 0;
}