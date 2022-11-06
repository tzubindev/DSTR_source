#include <iostream>

using namespace std;

class Validation {

public:
	static const int NAME = 0;
	static const int PASSPORT = 1;
	static const int IC = 2;
	static const int SNAME = 3;
	static const int SDIST = 4;
	static const int SFARE = 5;
	static const int STIME = 6;
	static const int SSPOT = 7;
	bool isOnlyDigit = true;

	Validation() {}

	bool validate(string str, int type) {
		
		switch (type) {
		case NAME:
			if (str.length() < 3) return false;
			for (int i = 0; i < str.length();i++) {
				if (isdigit(str[i])) return false;
				if (!isalpha(str[i]) && str[i] != ' ') return false;
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
		case SNAME:
			if (str.length() == 0) return false;
			break;
		case SDIST: case STIME:
			if (str.length() == 0) return false;
			for (char ch : str) if(!isdigit(ch)) return false;
			break;
		case SFARE:
			if (str.length() == 0) return false;
			for (char ch : str) if (!isdigit(ch) && ch != '.') return false;
			break;
		case SSPOT:
			if (str.length() == 0) return false;
			for (char ch : str) if (!isalnum(ch) && ch != '_' && ch != ';') return false;
			break;
		}




		return true;
	}


};