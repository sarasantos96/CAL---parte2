#include "Reservation.h"

using namespace std;

Reservation:: Reservation(){}

Reservation:: Reservation(int id,Date date, Passenger passenger, string destination){
	this->id= id;
	this->date=date;
	this->passenger= passenger;
	this->destination=destination;
}

const Date& Reservation:: getDate()const {
	return date;
}

void Reservation:: setDate(Date date) {
	this->date = date;
}

const string& Reservation:: getDestination() const {
	return destination;
}

void Reservation:: setDestination(const string& destinantion) {
	this->destination = destination;
}

const Passenger& Reservation:: getPassenger() const {
	return passenger;
}

void Reservation:: setPassenger(const Passenger& passenger) {
	this->passenger = passenger;
}

int Reservation:: getId() const{
	return id;
}
