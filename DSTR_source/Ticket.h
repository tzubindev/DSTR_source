#include <iostream>
#include "Customer.h"

using namespace std;

class Ticket {

private:
	int id = NULL;
	string sourceStation = NULL;
	string destinationStation = NULL;
	// dateTimeObject dateTime = NULL;
	int ticketAmount = NULL;
	double price = NULL;
	// timeObject depatureTime = NULL;
	Customer customerObj;

private:

	// Define datetime and depatureTime
	void autofill() {
		
		// Set current date time

		
		// Get nearest train arrive time


		// accumulate travel time between two stations 


		// train arrive time + accumulated travel time
	
	}


public:

	Ticket() {}

	Ticket(int ID, string Source, string Destination, int amount, Customer customer) {
		id = ID;
		sourceStation = Source;
		destinationStation = Destination;
		ticketAmount = amount;
		customerObj = customer;

		autofill();
	}




};