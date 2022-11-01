#include <iostream>
#include "Ticket.h"

using namespace std;

class Transaction {

private:
	string TransactionID = "";
	Ticket TicketObject;

public:
	Transaction() {}

	Transaction(int transactionId, Ticket ticket) {
		TransactionID = "T_" + to_string(transactionId);
		TicketObject = ticket;
	}

	string getTransactionId() {
		return TransactionID;
	}

	Ticket getTicket() {
		return TicketObject;
	}

	string toString() {
		return 
			TransactionID + ";"
			+ TicketObject.toString();
	}


};