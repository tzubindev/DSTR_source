#include <string>
#include <windows.h>
#include "Menu.h"

using namespace std;



class AdminMenu : Menu {

private:
	TemporaryStorage* storage = nullptr;

	// Implementation
public:
	AdminMenu(TemporaryStorage* storage) {
		this->storage = storage;

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
		DoublyLinkedList<string> purchaseRecord = storage->getSubwayStations();


		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			for (int j = 0; j < purchaseRecord.getHeight(); j++) {
				cout << purchaseRecord.getItem(i, j) << ' ';
			}
			cout << endl;
		}
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
		setTab(5);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Admin Login\n";
		ConsoleColor().setColor(Color.WHITE);

		drawLine('=', MAX_WIDTH);
		cout << '\n';
		setTab(3);
		cout << "Please fill in your username and password.\n\n";
		drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string username = getInput("USERNAME");
		string password = getInput("PASSWORD");

		// Verification here [Ghassan]



		return true;
	}

	string getInput() {

		bool isTrimmedLeft = false;
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		cout << "ADMIN > ";
		string input, final = "";
		cin >> input;
		ConsoleColor().setColor(Color.WHITE);

		// lowercase
		for (char ch : input) {
			if (ch != ' ') isTrimmedLeft = true;
			if (isTrimmedLeft)
				final += tolower(ch);
		}
		return final;
	}

	string getInput(string type) {

		bool isTrimmedLeft = false;
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		cout << type + " > ";

		string input, final = "";
		cin >> input;
		ConsoleColor().setColor(Color.WHITE);

		// lowercase
		for (char ch : input) {
			if (ch != ' ') isTrimmedLeft = true;
			if (isTrimmedLeft)
				final += tolower(ch);
		}
		return final;
	}

};