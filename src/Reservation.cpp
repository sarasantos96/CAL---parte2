#include "Reservation.h"

using namespace std;

static int ID=0;

Reservation:: Reservation(){}

Reservation:: Reservation(Date date, Passenger passenger, int price, Date arrival, string destination){
	this->id= ID;
	this->date=date;
	this->passenger= passenger;
	this->price=price;
	this->arrival=arrival;
	this->destination=destination;
	ID++;
}

const Date& Reservation:: getArrival() const {
	return arrival;
}

void Reservation:: setArrival(const Date& arrival) {
	this->arrival = arrival;
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

int Reservation:: getPrice() const {
	return price;
}

void Reservation:: setPrice(int price) {
	this->price = price;
}

int Reservation:: getId() const{
	return id;
}
