#include <iostream>
#include "Customer.h"

using namespace std;

class Ticket {

private:
	string TicketID = "TKID_";
	string sourceStation = "";
	string destinationStation = "";
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
		TicketID += ID;
		sourceStation = Source;
		destinationStation = Destination;
		ticketAmount = amount;
		customerObj = customer;

		autofill();
	}




};