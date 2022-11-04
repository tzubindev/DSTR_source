#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

class PassengerMenu {

private:
	TemporaryStorage* storage;

public:

	PassengerMenu() {}

	PassengerMenu(TemporaryStorage *TempStorage) {
		storage = TempStorage;
		for (int i = 0; i < 100; i++) cout << '\n';
		cout << login() << endl;
	}



	// Display Travel Route Format
	/*
	************************************************************************
		Station ID: SID			{2}||		Station Name: Name

		Previous
		Station Name: Name
		Distance	: 0				{need 1 tab}
		Price		: RM 0.4		{need 2 tabs}
		Time		: 3 mins		{need 2 tabs}

		Next
		Station Name: Name
		Distance	: 0				{need 1 tab}
		Price		: RM 0.4		{need 2 tabs}
		Time		: 3 mins		{need 2 tabs}

		NearbySightseeingSpots
		1) a
		2) b
	************************************************************************
	*/

	void DisplayTravelRoute(bool AscOrder) {
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);
		string temp = "", temp2 = "";

		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Display Travel Route", 6);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		if (AscOrder) {
			for (int i = 0; i < Stations.getSize(); i++) {
				cout << "\tStation ID: " << Stations.getItem(i, 0) << "\t\t" << "||\t" << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << endl << endl;

				cout << "\tNext\n";
				cout << "\tStation Name: " << Stations.getItem(i, 6) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				string foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);
				int cnt = 0;

				// count
				for (char ch : temp) {
					if (ch == ';') {
						cnt++;
					}
				}

				//Queue here
				Queue<string> q(cnt);

				//push item to queue

				for (char ch : temp) {
					if (ch == ';') {
						q.enqueue(temp2);
						temp2 = "";
					}
					else temp2 += ch;
				}

				int size = q.size();
				for (int j = 1; j <= size; j++) {
					cout << "\t" << j << ") " << q.dequeue() << endl;
				}

				cout << endl;
				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				ConsoleColor();
			}
		}
		else {
			for (int i = Stations.getSize() -1 ; i >= 0; i--) {
				cout << "\tStation ID: " << Stations.getItem(i, 0) << "\t\t" << "||\t" << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << endl << endl;

				cout << "\tNext\n";
				cout << "\tStation Name: " << Stations.getItem(i, 2) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 3) << " KM" << endl;
				string foo = Stations.getItem(i, 4);
				foo = foo.substr(0, 4);

				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 5) << " mins" << endl;
				cout << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);
				int cnt = 0;

				// count
				for (char ch : temp) {
					if (ch == ';') {
						cnt++;
					}
				}

				//Queue here
				Queue<string> q(cnt);

				//push item to queue

				for (char ch : temp) {
					if (ch == ';') {
						q.enqueue(temp2);
						temp2 = "";
					}
					else temp2 += ch;
				}

				int size = q.size();
				for (int j = 1; j <= size; j++) {
					cout << "\t" << j << ") " << q.dequeue() << endl;
				}

				cout << endl;
				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				ConsoleColor();
			}
		}
		cout << endl;
	}

	void chooseAndDisplayTravelRoute() {
		string input;
		cout << "1- Titiwangsa --> Chan Sow Lin" << "\n" <<
			"OR" << "\n" <<
			"2- Chan Sow Lin --> Titiwangsa"<< "\n" <<
			"Please Select the Travel Route:";
		cin >> input;
		if (input == "1") {
			DisplayTravelRoute(true);
		}
		else if (input == "2") {
			DisplayTravelRoute(false);
		}
		else {
			cout << "Please select the correct travel route:";
		}
	}


	void searchStationDetails() {
		
	}
	void viewDetailsBetweenTwoCities();
	bool purchaseSubwayTicket();
	void viewPurchaseTransactionHistory();
	bool deletePurchaseTransaction();

private:
	bool login() {
		Menu* tempMenuObj = new Menu(true);
		tempMenuObj->drawLine('=', MAX_WIDTH);
		tempMenuObj->setTab(5);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Passanger Login\n";
		ConsoleColor().setColor(Color.WHITE);

		tempMenuObj->drawLine('=', MAX_WIDTH);
		cout << '\n';
		tempMenuObj->setTab(3);
		cout << "Please fill in your username and password.\n\n";
		tempMenuObj->drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string icOrPassportNo = getInput("PASSPORT NO // IC");
		string password = getInput("PASSWORD");

		// Verification here [Ghassan]
		LinkedList<Customer> Details = storage->getPassangerDetails();
		bool usernameChecked = false, UNcorrect = false, PWcorrect = false, isEnd = false;
		for (int i = 0; i < Details.getSize(); i++) {
			usernameChecked = false;
			UNcorrect = false;
			PWcorrect = false;
			for (auto detail : Details.getItem(i).toString()) {
				if (usernameChecked) {
					if (password == Details.getItem(i).Password) PWcorrect = true;
					isEnd = true;
				}
				else {
					if (icOrPassportNo == Details.getItem(i).PassportNo || icOrPassportNo == Details.getItem(i).IdentityNo) UNcorrect = true;
					usernameChecked = true;
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
		cout << "Passanger > ";
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
