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
		Station ID: SID				
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
