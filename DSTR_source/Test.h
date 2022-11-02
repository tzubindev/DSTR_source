#include <iostream>
#include "AdminMenu.h"
#include "PassengerMenu.h"


using namespace std;

void Test()
{

	// Build Storage
	TemporaryStorage* storage = new TemporaryStorage();
	Menu * mainMenu = new Menu();
	while (true) {
		while (mainMenu->getErrorStatus()) {
			mainMenu = new Menu();
		}

		if (!mainMenu->getExitStatus()) {
			if (mainMenu->getUserType() == 'A') {

				AdminMenu* adminMenu = new AdminMenu(storage);
				//adminMenu->viewPurchaseTransactions();
			}
			else {
				PassengerMenu* passengerMenu = new PassengerMenu(storage);
				passengerMenu->DisplayTravelRoute();
			}
		}
		else break;

		mainMenu = new Menu();
	}

	//LinkedList<int> lst;

	//lst.insertAtbeginning(1);
	//lst.insertAtbeginning(2);
	//lst.insertAtbeginning(3);
	//lst.insertAtbeginning(4);
	//lst.insertAtbeginning(5);
	//lst.insertAtbeginning(6);

	//cout << lst.getItem(3);

}