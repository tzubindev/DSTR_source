#include <stdio.h>
#include <time.h>
#include <iostream>

using namespace std;

class DateTime {

	time_t now = time(NULL);
	char str[26] = {};

public:

	DateTime() {
		ctime_s(str, 26, &now);
	}

	string getDateTime() {
		return str;
	}



};
