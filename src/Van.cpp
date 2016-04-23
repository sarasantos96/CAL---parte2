#include "Van.h"

using namespace std;

Van::Van(){};

Van:: Van(string lPlate, int nPassengers){
	this->lPlate=lPlate;
	this->nPassengers=nPassengers;
}

string Van:: getLPlate() const {
	return lPlate;
}

void Van:: setLPlate(const string& lPlate) {
	this->lPlate = lPlate;
}

int Van:: getPassengers() const {
	return nPassengers;
}

void Van:: setPassengers(int nPassengers) {
	this->nPassengers = nPassengers ;
}

const Date& Van:: getD() const {
	return d;
}

void Van:: setD(const Date& d) {
	this->d = d;
}

const vector<Reservation>& Van:: getReservations() const {
	return reservations;
}

void Van:: setReservations(const vector<Reservation>& reservations) {
	this->reservations = reservations;
}


void Van:: addReservation(Reservation r){
	reservations.push_back(r);
}

vector<Reservation> Van:: getReservations(){
	return reservations;
}
void Van:: setReservations(vector<Reservation> res){
	reservations = res;
}
