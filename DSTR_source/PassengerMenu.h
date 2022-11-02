#include <iostream>
#include <string>

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
		Station ID: SID			{2}||{2}		Station Name: Name

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
		
		tempMenuObj->drawLine('-', MAX_WIDTH);

		for (int i = 0; i < Stations.getSize(); i++) {
			for (int j = 0; j < Stations.getHeight(); j++) {
				cout << Stations.getItem(i,j) << "\t";
			}
			cout << endl << endl;
		}

	}

	void chooseAndDisplayTravelRoute();
	void searchStationDetails();
	void viewDetailsBetweenTwoCities();
	bool purchaseSubwayTicket();
	void viewPurchaseTransactionHistory();
	bool deletePurchaseTransaction();

};
