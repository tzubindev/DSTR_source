#include <iostream>
#include "AdminMenu.h"

using namespace std;

void Test()
{
	
	// Build Storage
	TemporaryStorage* storage = new TemporaryStorage();
	Menu *mainMenu = new Menu();

	while (!mainMenu->getExitStatus()) {
		if (mainMenu->getUserType() == 'A') {

			AdminMenu* adminMenu = new AdminMenu(storage);
			adminMenu->viewPurchaseTransactions();
		}
		else {

			cout << 'P';
		}
	}
}