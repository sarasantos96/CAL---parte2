#include <iostream>

using namespace std;

Date:: Date(int day, int month, int year, int hour, int minutes){
	this->day=day;
	this->month= month;
	this->year= year;
	this-> hour= hour;
	this->minutes=minutes;
}

int Date:: getDay() const {
	return day;
}

void Date:: setDay(int day) {
	this->day = day;
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

int Date:: getMonth() const {
	return month;
}

void Date:: setMonth(int month) {
	this->month = month;
}

int Date:: getYear() const {
	return year;
}

void Date:: setYear(int year) {
	this->year = year;
}
