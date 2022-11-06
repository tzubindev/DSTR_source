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
				adminMenu->deleteTransaction();
			}
			else {
				PassengerMenu* passengerMenu = new PassengerMenu();
				string input;
				cout << "1- Log in \n2- New User" << endl;
				cin >> input;
				if (input == "1" || input == "one") {
					PassengerMenu* passengerMenu2 = new PassengerMenu(storage, true);
					if (passengerMenu2->login()) {
						passengerMenu2->deletePurchaseTransaction();
					}
					else
					{
						passengerMenu->printError(Error().WRONG_INPUT);
					}
				}
				else if (input == "2" || input == "two") {
					passengerMenu->purchaseSubwayTicket();
				}
				else
				{
					passengerMenu->printError(Error().WRONG_INPUT);
				}
			}
		}
		else break;

		mainMenu = new Menu();
	}

	


	//Queue<string> q(5);
	//q.enqueue("d");
	//q.enqueue("s");
	//cout<< q.peek() << "\n";
	//q.dequeue();
	//q.show();

	//lst.insertAtbeginning(1);
	//lst.insertAtbeginning(2);
	//lst.insertAtbeginning(3);
	//lst.insertAtbeginning(4);
	//lst.insertAtbeginning(5);
	//lst.insertAtbeginning(6);

	//cout << lst.getItem(3);

}



