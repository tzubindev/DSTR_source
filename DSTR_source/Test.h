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
				adminMenu->editSubwayInformation();
			}
			else {
				PassengerMenu* passengerMenu = new PassengerMenu(storage);
				string input;
				cout << "1- Log in \n2- Register" << endl;
				cin >> input;
				if (input == "1") {
					PassengerMenu* passengerMenu2 = new PassengerMenu(storage, true);
					if (passengerMenu2->login()) {
						passengerMenu2->chooseAndDisplayTravelRoute();
					}
					else
					{
						passengerMenu->printError(Error().WRONG_INPUT);
					}
				}
				else if (input == "2") {
					passengerMenu->registerPassenger();
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



