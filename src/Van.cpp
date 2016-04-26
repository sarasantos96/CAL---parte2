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

const vector<Date> & Van:: getD() const {
	return dates;
}

void Van:: setD(const vector<Date> & d) {
	this->dates = d;
}

const vector< vector <Reservation> >& Van:: getReservations() const {
	return reservations;
}

void  Van:: setReservations(const vector<vector<Reservation> >& reservations) {
	this->reservations = reservations;
}

void Van:: addDate(Date &d){
	dates.push_back(d);
}

void Van:: addReservations(vector<Reservation> r){
	reservations.push_back(r);
}

void Van:: setSortedTrips(int res, vector<Reservation> trip){
	trips.push_back(trip);
}

vector<vector<Reservation> > Van::getTrips() const{
	return trips;
}
