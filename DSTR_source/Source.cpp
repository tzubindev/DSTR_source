#include <iostream>
#include <string>
#include "AdminMenu.h"
#include "PassengerMenu.h"
#include <Windows.h>

using namespace std;

void setSize();

int main() {

	setSize();
	TemporaryStorage* storage = new TemporaryStorage();
	Menu* menu = new Menu();
	Menu* tempMenuObj = new Menu(true);

	while (true) {

		if (menu->getExitStatus()) {
			tempMenuObj->drawLine('*', MAX_WIDTH);
			tempMenuObj->makeTitleBlock("Exit", 6);
			cout << endl;
			tempMenuObj->drawLine('*', MAX_WIDTH);
			break;
		}

		if (menu->getErrorStatus()) {
			menu = new Menu();
		}
		else if (menu->getUserType() == 'P') {
			// Passenger
			PassengerMenu* passengerMenu = new PassengerMenu(storage);
			cout << endl;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			cout << endl;

			string choice;
			while (true) {
				tempMenuObj->setTab(6);
				cout << "1 - Register\n";
				tempMenuObj->setTab(6);
				cout << "2 - Login\n";
				tempMenuObj->setTab(6);
				cout << "3 - Exit\n";

				cout << "CHOICE> ";
				cin >> choice;

				if (choice == "1" || choice == "2" || choice == "3") break;
				else cout << "Error: Wrong Input.\n";
			}
			
			// title block 
			if (choice == "1" || choice == "2") {

				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				tempMenuObj->makeTitleBlock("Passenger Menu", 6);
				cout << endl;
				tempMenuObj->drawLine('*', MAX_WIDTH);
				cout << endl;
				ConsoleColor();
			}

			// Split direction
			if (choice == "1") {
				passengerMenu->registerPassenger();
			}
			else if (choice == "2") {

				if (passengerMenu->login()) {
					
					// if true, customerObj will be caught
					string option = "";
					while (option != "7") {
						cout << "1- Choose the travel route and Display the list" << endl;
						cout << "2- Search the subway station details" << endl;
						cout << "3- View the details between two selected cities" << endl;
						cout << "4- Purchase subway ticket" << endl;
						cout << "5- View purchase transaction history " << endl;
						cout << "6- Delete purchase transaction " << endl;
						cout << "7- Logout " << endl;
						cout << endl;

						//validation

						switch (stoi(option)) {
						case 1:
							passengerMenu->chooseAndDisplayTravelRoute();
							break;
						case 2:
							passengerMenu->searchStationDetails();
							break;
						case 3:
							passengerMenu->viewDetailsBetweenTwoCities();
							break;
						case 4:
							passengerMenu->purchaseSubwayTicket();
							break;
						case 5:
							passengerMenu->viewPurchaseTransactionHistory();
							break;
						case 6:
							passengerMenu->deletePurchaseTransaction();
							break;
						case 7:
							break;
						default:
							cout << "Wrong Input" << endl;
						}
						tempMenuObj->drawLine('*', MAX_WIDTH);
						ConsoleColor();
					}
				}
			}
			else {
				storage = passengerMenu->outputLatestStorage();
				menu = new Menu();
			}
		}
		else if (menu->getUserType() == 'A') {
			// Admin
			AdminMenu* adminMenu = new AdminMenu(storage);
			cout << endl;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			cout << endl;

			if (adminMenu->login()) {
				while (true) {
					ConsoleColor().setColor(Color.YELLOW);
					tempMenuObj->drawLine('*', MAX_WIDTH);
					tempMenuObj->makeTitleBlock("Admin Menu", 6);
					tempMenuObj->drawLine('*', MAX_WIDTH);
					cout << endl;

					cout << "1- Add new subway station information " << endl;
					cout << "2- Edit current subway stations?information" << endl;
					cout << "3- View all purchase transactions " << endl;
					cout << "4- Sort purchase" << endl;
					cout << "5- Search specific customer ticket purchase information " << endl;
					cout << "6- Edit specific customer ticket purchase information " << endl;
					cout << "7- Delete specific customer ticket purchase information " << endl;
					cout << "8- Logout " << endl;
					string option = adminMenu->getInput("Please Enter the Option: ");

					// validation

					switch (stoi(option)) {
					case 1:
						adminMenu->addSubwayStation();
						break;
					case 2:
						adminMenu->editSubwayInformation();
						break;
					case 3:
						adminMenu->viewPurchaseTransactions();
						break;
					case 4:
						adminMenu->sortPurchaseTransactions();
						break;
					case 5:
						adminMenu->searchTicketInformation();
						break;
					case 6:
						adminMenu->editTicketInformation();
						break;
					case 7:
						adminMenu->deleteTransaction();
						break;
					case 8:
						storage = adminMenu->outputLatestStorage();
						break;
					default:
						cout << "Wrong Input" << endl;
					}
					tempMenuObj->drawLine('*', MAX_WIDTH);
					ConsoleColor();
					if (option == "8") break;

				}
			}
		}
		else {
			cout << "Error: Uncaught type\n";
			menu = new Menu();
		}
	}
	return 0;
}

void setSize() {
	// Set size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE); // 1000 width, 600 height
}