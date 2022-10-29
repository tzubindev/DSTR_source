#include <iostream>
#include <string>
#include <windows.h>
#include "Menu.h"

using namespace std;



class AdminMenu : Menu {

	// Implementation
public:
	AdminMenu() {
		for (int i = 0; i < 100; i++) cout << '\n';
		login();
	}

	bool addSubwayStation() {
		return true;
	}

	bool editSubwayInformation() {
		return true;
	}

	void viewPurchaseTransactions() {

	}

	void sortPurchaseTransactions() {

	}

	void searchTicketInformation() {

	}

	bool editTicketInformation() {
		return true;
	}

	bool deleteTicket() {
		return true;
	}

private:

	bool login() {
		drawLine('=', MAX_WIDTH);
		setTab(3);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Admin Login";
		ConsoleColor().setColor(Color.WHITE);

		drawLine('=', MAX_WIDTH);
		cout << '\n';
		setTab(2);
		cout << "";
		drawLine('-', MAX_WIDTH);
	}

};