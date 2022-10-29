#include <iostream>

using namespace std;

class Customer {

public:
	string CustomerID = "CID_";
	string CustomerName = "";
	string IdentityNo = "";
	string PassportNo = "";
	bool isLocal = (IdentityNo != "") ? true: false;

	Customer() {}

	void setInfo(int customerId, string name, string number, bool local) {
		CustomerID += customerId;
		CustomerName = name;
		if (local) IdentityNo += number;
		else PassportNo += number;
	}


};