#include <iostream>

using namespace std;

class Customer {


private:
	string CustomerID = NULL;
	string CustomerName = NULL;
	string IdentityCardNo = "";
	string PassportNo = "";
	bool isLocal; // true -> local ; false -> foreigner



public:
	
	Customer(int ID, string customerName, string Number, bool local) {

		CustomerID = "CID_"+ID;
		CustomerName = customerName;
		isLocal = local;
		
		if (isLocal) IdentityCardNo = Number;
		else PassportNo = Number;
	}

};