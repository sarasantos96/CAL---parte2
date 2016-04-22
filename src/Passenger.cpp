#include "Passenger.h"

using namespace std;

Passenger:: Passenger(){}

Passenger:: Passenger(string name, string nif){
	this->name=name;
	this->nif=nif;
}

string Passenger:: getName() const {
	return name;
}

void Passenger:: setName(const string name) {
	this->name = name;
}

string Passenger:: getNif() const {
	return nif;
}

void Passenger:: setNif(string nif) {
	this->nif = nif;
}
