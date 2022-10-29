#include <iostream>
#include "Menu.h"

using namespace std;

void Test()
{
	
	Menu *mainMenu = new Menu();
	if (mainMenu->getUserType() == 'A') {
		delete mainMenu;
		AdminMenu adminMenu = AdminMenu();
	}
	else {
		delete mainMenu;
		AdminMenu adminMenu = AdminMenu();
	}
}