#include <iostream>
#include "Menu.h"

using namespace std;

class PassengerMenu : Menu{

private:
	TemporaryStorage storage;

public:

	PassengerMenu(TemporaryStorage &TempStorage) {
		this->storage = TempStorage;
	}

	void DisplayTravelRoute() {

	}
	void chooseAndDisplayTravelRoute();
	void searchStationDetails();
	void viewDetailsBetweenTwoCities();
	bool purchaseSubwayTicket();
	void viewPurchaseTransactionHistory();
	bool deletePurchaseTransaction();

};
