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
				/*adminMenu->viewPurchaseTransactions();*/
			}
			else {

				// here login
				//passanger login in test file
				//return bool
				/*PassengerMenu* login = PassengerMenu->login();*/

				//PassengerMenu* passengerMenu = new PassengerMenu(storage, true);
				//passengerMenu->login();
				////passengerMenu->viewPurchaseTransactionHistory();
				////passengerMenu->viewDetailsBetweenTwoCities();
				//passengerMenu->purchaseSubwayTicket();
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



