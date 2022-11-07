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
	Menu* tempMenuObj = new Menu(true);
	// Passenger
	PassengerMenu* passengerMenu = new PassengerMenu(storage);
	cout << endl;
	tempMenuObj->drawLine('-', MAX_WIDTH);
	cout << endl;

	ConsoleColor().setColor(Color.YELLOW);
	tempMenuObj->drawLine('*', MAX_WIDTH);
	tempMenuObj->makeTitleBlock("Passenger Menu", 6);
	tempMenuObj->drawLine('*', MAX_WIDTH);
	cout << endl;

	cout << "1- Choose the travel route and Display the list" << endl;
	cout << "2- Search the subway station details" << endl;
	cout << "3- View the details between two selected cities" << endl;
	cout << "4- Purchase subway ticket" << endl;
	cout << "5- View purchase transaction history " << endl;
	cout << "6- Delete purchase transaction " << endl;
	cout << "7- Logout " << endl;
	string option = passengerMenu->getInput("Please Enter the Option: ");
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

	// Admin
	AdminMenu* adminMenu = new AdminMenu(storage);
	cout << endl;
	tempMenuObj->drawLine('-', MAX_WIDTH);
	cout << endl;

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
	option = adminMenu->getInput("Please Enter the Option: ");
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
		break;
	default:
		cout << "Wrong Input" << endl;
	}
	tempMenuObj->drawLine('*', MAX_WIDTH);
	ConsoleColor();

	return 0;
}

void setSize() {
	// Set size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE); // 1000 width, 600 height
}