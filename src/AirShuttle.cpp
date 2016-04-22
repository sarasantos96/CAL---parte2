#include "AirShuttle.h"
#include "Exceptions.h"

using namespace std;

AirShuttle:: AirShuttle(){}

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
bool AirShuttle:: removeReservation(int id){
	int i;
	bool exist=false;
	for(i=0;i < reservations.size();i++){
		if(reservations[i].getId()== id){
			exist=true;
			break;
		}
	}
	if(exist)
		reservations.erase(reservations.begin()+i);
	else{
		throw InexistentReservationException(id);
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

vector<Reservation> AirShuttle:: getReservationByDate(Date &d){
	vector<Reservation> r;

	for(unsigned int i=0; i<reservations.size();i++){
		Date d1= reservations[i].getDate();
		if(d1 == d)
			r.push_back(reservations[i]);
	}

	return r;
}
vector<Reservation> AirShuttle:: getReservationByPassenger(Passenger p){
	vector<Reservation> r;

	for(unsigned int i=0; i<reservations.size();i++){
		Passenger p1= reservations[i].getPassenger();
		if(p1 == p)
			r.push_back(reservations[i]);
	}

	return r;
}

bool AirShuttle:: changePassengerNIF(int oldNif, int newNif){
	unsigned int i;
	bool found=false;

	for(i=0; i< reservations.size(); i++){
		if(reservations[i].getPassenger().getNif() == oldNif){
			found=true;
			break;
		}
	}
	if(found){
		Passenger p = reservations[i].getPassenger();
		p.setNif(newNif);
		reservations[i].setPassenger(p);
	}
	else{
		throw InexistentPassengerException();
		return false;
	}

	return true;
}
bool AirShuttle:: changePassengerName(string oldName, string newName){
	unsigned int i;
	bool found=false;

	for(i=0; i< reservations.size(); i++){
		if(reservations[i].getPassenger().getName() == oldName){
			found=true;
			break;
		}
	}
	if(found){
		Passenger p = reservations[i].getPassenger();
		p.setName(newName);
		reservations[i].setPassenger(p);
	}
	else{
		throw InexistentPassengerException();
		return false;
	}

	return true;
}
