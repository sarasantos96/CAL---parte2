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




