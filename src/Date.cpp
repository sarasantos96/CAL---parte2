#include "Date.h"

using namespace std;

Date:: Date(){}

Date:: Date( int hour, int minutes){

	this-> hour= hour;
	this->minutes=minutes;
}

int Date:: getHour() const {
	return hour;
}

void Date:: setHour(int hour) {
	this->hour = hour;
}

int Date:: getMinutes() const {
	return minutes;
}

void Date:: setMinutes(int minutes) {
	this->minutes = minutes;
}
