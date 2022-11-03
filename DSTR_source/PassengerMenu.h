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
	}



	// Display Type
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

	void DisplayTravelRoute() {
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

		for (int i = 0; i < Stations.getSize(); i++) {			
			cout << "\tStation ID: " << Stations.getItem(i, 0) << "\t\t" << "||\t" << "Station Name: " << Stations.getItem(i, 1) << endl;
			cout << endl << endl;

			cout << "\tPrevious\n";
			cout << "\tStation Name: " << Stations.getItem(i, 2) << endl;
			cout << "\tDistance\t: " << Stations.getItem(i, 3) << " KM" << endl;
			string foo = Stations.getItem(i, 4);
			foo = foo.substr(0, 4);

			cout << "\tPrice\t\t: " << "RM " << foo << endl;
			cout << "\tTime\t\t: " << Stations.getItem(i, 5) << " mins" << endl;
			cout << endl;

			cout << "\tNext\n";
			cout << "\tStation Name: " << Stations.getItem(i, 6) << endl;
			cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
			foo = Stations.getItem(i, 8);
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

		cout << endl;
	}

	void chooseAndDisplayTravelRoute();
	void searchStationDetails();
	void viewDetailsBetweenTwoCities();
	bool purchaseSubwayTicket();
	void viewPurchaseTransactionHistory();
	bool deletePurchaseTransaction();

};
