#include <iostream>
#include "Ticket.h"
#include "GlobalAttribute.h"

using namespace std;

class Transaction {

private:
	int TransactionID = -1;
	Ticket TicketObject;

public:
	Transaction(GlobalAttribute globalAttribute, Ticket ticket) {
		TransactionID = globalAttribute.getCurrentTransactionId();
		TicketObject = ticket;
	}

	int getTransactionId() {
		return TransactionID;
	}

	Ticket getTicket() {
		return TicketObject;
	}




};