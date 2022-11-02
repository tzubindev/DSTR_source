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

	void DisplayTravelRoute() {
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		for (int i = 0; i < Stations.getSize(); i++) {
			for (int j = 0; j < Stations.getHeight(); j++) {
				cout << Stations.getItem(i,j) << ' ';
			}
			cout << endl;
		}

	}

	void chooseAndDisplayTravelRoute();
	void searchStationDetails();
	void viewDetailsBetweenTwoCities();
	bool purchaseSubwayTicket();
	void viewPurchaseTransactionHistory();
	bool deletePurchaseTransaction();

};
