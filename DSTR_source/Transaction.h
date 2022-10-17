#include <iostream>
#include "Ticket.h"

using namespace std;

class Transaction {

private:
	int TransactionID = -1;
	Ticket TicketObject;

public:
	Transaction(TemporaryStorage storage, Ticket ticket) {
		TransactionID = storage.getCurrentTransactionId();
		TicketObject = ticket;
	}

	int getTransactionId() {
		return TransactionID;
	}

	Ticket getTicket() {
		return TicketObject;
	}




};