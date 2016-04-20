#include "AirShuttle.h"
#include "Exceptions.h"

using namespace std;

AirShuttle:: AirShuttle(vector<Reservation> reservations, vector<Van> vans){
	this->reservations=reservations;
	this->vans=vans;
}
vector<Passenger> AirShuttle:: getPassengers(){
	vector<Passenger> p;
	for(int i=0; i< reservations.size();i++){
		p.push_back(reservations[i].getPassenger());
	}
	return p;
}
vector<Reservation> AirShuttle:: getReservations(){
	return reservations;
}
vector<Van> AirShuttle:: getVans(){
	return vans;
}
bool AirShuttle:: addReservation(Reservation r){
	for(int i=0; i< reservations.size(); i++){
		if(reservations[i]==r)
			throw DuplicateReservationException(r);
			return false;
	}

	reservations.push_back(r);
}
bool AirShuttle:: removeReservation(Reservation r){
	int i;
	bool exist=false;
	for(i=0;i < reservations.size();i++){
		if(reservations[i]== r){
			exist=true;
			break;
		}
	}
	if(exist)
		reservations.erase(reservations.begin()+i);
	else{
		throw InexistentReservationException(r);
		return false;
	}
	return true;
}
bool AirShuttle:: addVan(Van v){
	for(int i=0; i< vans.size(); i++){
		if(vans[i]==v)
			throw DuplicateVanException(v);
		return false;
	}

	vans.push_back(v);
}
bool AirShuttle:: removeVan(Van v){
	int i;
	bool exist=false;
	for(i=0;i < vans.size();i++){
		if(vans[i]== v){
			exist=true;
			break;
		}
	}

	if(exist)
		vans.erase(vans.begin()+i);
	else{
		throw InexistentVanException(v);
		return false;
	}
	return true;
}

