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
		if(reservations[i]==r) {
			throw DuplicateReservationException(r);
			return false;
		}
	}

	reservations.push_back(r);
	return true;
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
		if(vans[i]==v){
			throw DuplicateVanException(v);
		}
	}
	vans.push_back(v);
	return true;
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

bool AirShuttle:: changePassengerNIF(string oldNif, string newNif){
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

void AirShuttle:: setReservations(vector<Reservation> res){
	this->reservations=res;
}

void AirShuttle:: passengerTransportation(){
	int i=0, van=0;
	int waitTime = 30;//minutes
	Date d;

	for(;i<reservations.size();i++){
		int seats = vans[van].getPassengers();
		vans[van].addReservation(reservations[i]);
		d= Date(reservations[i].getDate().getHour(),reservations[i].getDate().getMinutes());
		bool wait = true;
		int j= i+1;
		while(seats > 0 && wait && j<reservations.size()){
			int dif = ((reservations[j].getDate().getHour() * 60)+ reservations[j].getDate().getMinutes()) -
					((d.getHour() * 60)+ d.getMinutes());
			if(dif>30){
				wait=false;
				van++;
			}
			else{
				vans[van].addReservation(reservations[j]);
				d=  Date(reservations[j].getDate().getHour(),reservations[j].getDate().getMinutes());
				seats--;
				j++;
			}
			if(van >= vans.size())
				van=0;
		}
		vans[van].setD(d);
		i=j-1;
	}
	cout<< vans[0].getReservations().size()<<endl;
	cout<< vans[1].getReservations().size()<<endl;
}
