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

		for (int i = 0; i < 10; i++) cout << '\n';
	}

	bool addSubwayStation() {
		return true;
	}

	bool editSubwayInformation() {
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);
		string stationID;
		string temp, temp2;
		for (int i = 0; i < Stations.getSize(); i++) {
			cout << "Station ID: " << Stations.getItem(i, 0) << endl;
			cout << "Station Name: " << Stations.getItem(i, 1) << endl;
			cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
			string foo = Stations.getItem(i, 8);
			foo = foo.substr(0, 4);
			cout << "\tPrice\t\t: " << "RM " << foo << endl;
			cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
			cout << endl << endl;

			cout << "\tNearby Sightseeing Spots\n";
			temp = Stations.getItem(i, 10);

			//int cnt = 0;

			//// count
			//for (char ch : temp) {
			//	if (ch == ';') {
			//		cnt++;
			//	}
			//}

			////Queue here
			//Queue<string> q(cnt);

			////push item to queue

			//for (char ch : temp) {
			//	if (ch == ';') {
			//		q.enqueue(temp2);
			//		temp2 = "";
			//	}
			//	else temp2 += ch;
			//}

			//int size = q.size();
			//for (int j = 1; j <= size; j++) {
			//	cout << "\t" << j << ") " << q.dequeue() << endl;
			//}

			cout << endl;
			ConsoleColor().setColor(Color.YELLOW);
			tempMenuObj->drawLine('*', MAX_WIDTH);
			ConsoleColor();
		}
		cout << "Please enter the station ID to edit it:";
		cin >> stationID;
		for (int i = 0; i < Stations.getSize(); i++) {
			if (stationID == Stations.getItem(i, 0)) {
				cout << "Station ID: " << Stations.getItem(i, 0) << endl;
				cout << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				string foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);

				int option;
				cout << "1- Station Name \n2- Price\n3- Time" << endl;
				cout << "Enter the number thing that you want to edit:";
				cin >> option;
				string input;

				switch (option)
				{
				case 1:
					cout << "Enter the new name of the staion:";
					cin >> input;
					break;
				case 2:
					cout << "Enter the new distance:";
					cin >> input;
					break;
				case 3:
					cout << "Enter the new price:";
					cin >> input;
					break;
				default:
					break;
				}
				cout << "Station ID: " << Stations.getItem(i, 0) << endl;
				cout << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl << endl;
				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);

			}
		}
		return true;
	}

	void viewPurchaseTransactions() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("View Purchase Transactions", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		cout << endl;

		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			cout << purchaseRecord.getItem(i).toString() << endl;
		}

		delete tempMenuObj;
	}

	// no complete
	void sortPurchaseTransactions() {

	}

	void searchTicketInformation() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);
		string searchTicketID = "";

		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("View Tickect Information", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();

		cout << endl;

		searchTicketID = getInput("Insert the Ticket id to search for ticket:");

		cout << endl << endl;
		for (int i = 0; i < searchTicketID.length(); i++) searchTicketID[i] = toupper(searchTicketID[i]);
		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			if (searchTicketID == purchaseRecord.getItem(i).getTicket().TicketID) {
				tempMenuObj->setTab(1);
				cout << "TicketId: " << purchaseRecord.getItem(i).getTicket().TicketID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Source Station Id: " << purchaseRecord.getItem(i).getTicket().sourceStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Destination Station Id: " << purchaseRecord.getItem(i).getTicket().destinationStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Amount: " << purchaseRecord.getItem(i).getTicket().ticketAmount << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Price: " << "RM" << purchaseRecord.getItem(i).getTicket().price << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Departure Time: " << purchaseRecord.getItem(i).getTicket().depatureTime << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer ID: " << purchaseRecord.getItem(i).getTicket().customerObj.CustomerID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer Name: " << purchaseRecord.getItem(i).getTicket().customerObj.CustomerName << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Passport Number // IC: " << purchaseRecord.getItem(i).getTicket().customerObj.IdentityNo << purchaseRecord.getItem(i).getTicket().customerObj.PassportNo << endl << endl;
				delete tempMenuObj;
			}
			else {
				cout << "";
			}

			cout << endl;
			ConsoleColor().setColor(Color.YELLOW);
			tempMenuObj->drawLine('*', MAX_WIDTH);
			ConsoleColor();
		}
	}

	bool editTicketInformation() {
		return true;
	}

	void deleteTransaction() {
		DoublyLinkedList<Transaction> Transactions = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Delete Transaction", 6);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		cout << endl;
		
		if (Transactions.getSize() == 0) {
			tempMenuObj->setTab(4);
			cout << "No Data!";
			cout << endl;
			ConsoleColor().setColor(Color.YELLOW);
			tempMenuObj->drawLine('*', MAX_WIDTH);
			ConsoleColor();
			return;
		}
		for (int i = 0; i < Transactions.getSize(); i++) {
			tempMenuObj->setTab(2);
			cout << "Transaction ID : " << Transactions.getItem(i).getTransactionId() << endl;
			tempMenuObj->setTab(2);
			cout << "Customer ID : " << Transactions.getItem(i).getTicket().getCustomer().getCustomerID() << endl;
			tempMenuObj->setTab(2);
			cout << "Ticket Date and Time :" << Transactions.getItem(i).getTicket().getTicketDateTime() << endl;
		}

		cout << endl;
		string toDeleteID = tempMenuObj->getInput("TRANSACTION ID");
		for (int i = 0; i < toDeleteID.length();i++) toDeleteID[i] = toupper(toDeleteID[i]);
		bool isFound = false;

		// check record
		for (int i = 0; i < Transactions.getSize(); i++) {
			if (toDeleteID == Transactions.getItem(i).getTransactionId()) {
				isFound = true;
				break;
			}
		}

		if (!isFound) printError(Error().WRONG_INPUT);
		else {
			storage->deleteTransaction(toDeleteID);
		}

		if (isFound) {
			tempMenuObj->setTab(2);
			cout << toDeleteID << " is deleted successfully. " << endl;
			cout << endl;
			ConsoleColor().setColor(Color.YELLOW);
			tempMenuObj->drawLine('*', MAX_WIDTH);
			ConsoleColor();
		}
		delete tempMenuObj;
	}

	bool login() {
		Menu* tempMenuObj = new Menu(true);
		tempMenuObj->drawLine('=', MAX_WIDTH);
		tempMenuObj->setTab(6);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Admin Login\n";
		ConsoleColor().setColor(Color.WHITE);

		tempMenuObj->drawLine('=', MAX_WIDTH);
		cout << '\n';
		tempMenuObj->setTab(4);
		cout << "Please fill in your username and password.\n\n";
		tempMenuObj->drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string username = getInput("USERNAME");
		cout << "PASSWORD > ";
		string password = tempMenuObj->getPassword();

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

private:

	void printError(int errorType) {
		string ErrorStr = "";
		Menu* tempMenu = new Menu(true);

		switch (errorType) {
		case Error().WRONG_INPUT:
			ErrorStr = "Wrong input is given!";
			break;
		}

		// Error Displaying
		tempMenu->drawLine('-', MAX_WIDTH);
		cout << '\n';
		ConsoleColor().setColor(Color.RED);
		tempMenu->setTab(6);
		cout << ErrorStr << "\n\n";
		ConsoleColor().setColor(Color.WHITE);
		tempMenu->drawLine('-', MAX_WIDTH);
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