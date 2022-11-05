#include <string>
#include <windows.h>
#include "Menu.h"

using namespace std;



class AdminMenu {

private:
	TemporaryStorage* storage;

	// Implementation
public:
	AdminMenu(TemporaryStorage *TempStorage) {
		storage = TempStorage;

		for (int i = 0; i < 100; i++) cout << '\n';
		cout << login() << endl;
	}

	bool addSubwayStation() {
		return true;
	}

	bool editSubwayInformation() {
		return true;
	}

	void viewPurchaseTransactions() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();


		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			cout << purchaseRecord.getItem(i).toString() << endl;
		}
	}

	void sortPurchaseTransactions() {

	}

	void searchTicketInformation() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		string input;

		cout << "Insert the Ticket id to search for ticket:";
		cin >> input;
		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			if (input == purchaseRecord.getItem(i).getTicket().TicketID) {
				cout << purchaseRecord.getItem(i).toString() << endl;
			}
			else {
				cout << "Please enter the correct Ticket ID:";
			}
		}
	}

	bool editTicketInformation() {
		return true;
	}

	bool deleteTicket() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		string input;

		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			cout << purchaseRecord.getItem(i).toString() << endl;
			cout << "Insert the Ticket id to delete the ticket:";
			cin >> input;
			if (input == purchaseRecord.getItem(i).getTicket().TicketID) {
				purchaseRecord.deleteItemAt(i);
				cout << "deleted successfully";
			}
			else {
				cout << "please enter correct input";
			}
		}
		return true;
	}

private:

	bool login() {
		Menu *tempMenuObj = new Menu(true);
		tempMenuObj->drawLine('=', MAX_WIDTH);
		tempMenuObj->setTab(5);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Admin Login\n";
		ConsoleColor().setColor(Color.WHITE);

		tempMenuObj->drawLine('=', MAX_WIDTH);
		cout << '\n';
		tempMenuObj->setTab(3);
		cout << "Please fill in your username and password.\n\n";
		tempMenuObj->drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string username = getInput("USERNAME");
		string password = getInput("PASSWORD");

		// Verification here [Ghassan]
		LinkedList<string> Details = storage->getAdminDetails();
		string temp = "";
		bool usernameChecked = false, UNcorrect = false, PWcorrect = false, isEnd = false;
		for (int i = 0; i < Details.getSize(); i++) {
			/*cout << Details.getItem(i) << endl;*/
			usernameChecked = false;
			UNcorrect = false;
			PWcorrect = false;
			for (char ch : Details.getItem(i)) {
				if (ch != ',') {
					temp += ch;
				}
				else {
					if (usernameChecked) {
						if (password == temp) PWcorrect = true;
						isEnd = true;
					}
					else {
						if (username == temp) UNcorrect = true;
						usernameChecked = true;
					}
					temp = "";
				}
				if (isEnd) break;
			}
			if (PWcorrect && UNcorrect) return true;
		}
		free(tempMenuObj);
		return false;
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