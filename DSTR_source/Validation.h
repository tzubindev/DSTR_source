#include <iostream>

using namespace std;

class Validation {

public:
	static const int NAME = 0;
	static const int PASSPORT = 1;
	static const int IC = 2;
	bool isOnlyDigit = true;

	Validation() {}

	bool validate(string str, int type) {
		
		switch (type) {
		case NAME:
			if (str.length() < 3) return false;
			cout << str;
			for (int i = 0;i<str) {
				cout << ch;
				if (isdigit(ch)) return false; 
				if (!isalpha(ch) || ch != ' ') return false;
			}
			break;
		case PASSPORT:
			if (str.length() < 3 || str.length() > 20) return false;
			for (char ch : str) {
				if (ch == ' ' || !isdigit(ch) || !isalpha(ch)) return false;
				if (!isdigit(ch)) isOnlyDigit = false;
			}
			if (!isOnlyDigit) {
				if (stoi(str) == 0) return false;
			}
			break;
		case IC:
			if (str.length() != 12) return false;
			for (char ch : str) if (!isdigit(ch)) return false;
			break;
		}




		return true;
	}


};