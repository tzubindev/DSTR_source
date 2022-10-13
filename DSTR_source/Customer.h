#include <iostream>
#include "GlobalAttribute.h"

using namespace std;

class Customer {


private:
	int CustomerID = NULL;
	string CustomerName = NULL;
	string IdentityCardNo = "";
	string PassportNo = "";
	bool isLocal = IdentityCardNo != ""; // true -> local ; false -> foreigner



public:
	Customer();

	Customer(string customerName, string ID_CardNo, GlobalAttribute global) {
		CustomerID = global.getCurrentCustomerId();
		CustomerName = customerName;
		IdentityCardNo = ID_CardNo;
	}

	Customer(string customerName, string passportNo, GlobalAttribute global) {
		CustomerID = global.getCurrentCustomerId();
		CustomerName = customerName;
		PassportNo = passportNo;
	}

};