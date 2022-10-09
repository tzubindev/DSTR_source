#include <iostream>
#include <string>

using namespace std;

class Menu {

	// Data members


	// Common functionalities
public:
	bool identityCheck();
	//TempStorage getData(); // TempStorage is an object of a class




	// Passenger functionalities
public:
	virtual void afunction();
	virtual string bfunction();


	// Admin Functionalitites




};

class PassengerMenu : Menu {

	// Implementation
public:
	void afunction() {

	}

	string bfunction() {

	}
};