#include <iostream>

using namespace std;

class Customer {

public:
	string CustomerID = "";
	string CustomerName = "";
	string IdentityNo = "";
	string PassportNo = "";
	
	Customer() {}

	Customer(int customerId, string name, string number, bool isLocal) {
		CustomerID = "CID_" + to_string(customerId);
		CustomerName = name;
		if (isLocal) {
			IdentityNo += number;
			PassportNo = "NULL";
		}
		else {
			IdentityNo = "NULL";
			PassportNo += number;
		}
	}

	string toString() {
		return
			CustomerID + ";" +
			CustomerName + ";" +
			IdentityNo + ";" +
			PassportNo + ";";
	}


};