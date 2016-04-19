#include "Passenger.h"

using namespace std;

Passenger:: Passenger(){}

Passenger:: Passenger(string name, int nif){
	this->name=name;
	this->nif=nif;
}

string Passenger:: getName() const {
	return name;
}

void Passenger:: setName(const string name) {
	this->name = name;
}

int Passenger:: getNif() const {
	return nif;
}

void Passenger:: setNif(int nif) {
	this->nif = nif;
}
