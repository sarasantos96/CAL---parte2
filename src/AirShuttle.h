#ifndef SRC_AIRSHUTTLE_H_
#define SRC_AIRSHUTTLE_H_
#include <iostream>
#include <vector>
#include "Reservation.h"
#include "Van.h"
#include "Passenger.h"

using namespace std;

class AirShuttle{
private:
	vector<Reservation> reservations;
	vector<Van> vans;
public:
	AirShuttle();
	vector<Passenger> getPassengers();
	vector<Reservation> getReservations();
	vector<Van> getVans();
	bool addReservation(Reservation r);
	bool removeReservation(int id);
	bool addVan(Van v);
	bool removeVan(Van v);
	vector<Reservation> getReservationByDate(Date &d);
	vector<Reservation> getReservationByPassenger(Passenger p);
	bool changePassengerNIF(string oldNif, string newNif);
	bool changePassengerName(string oldName, string newName);
	void distributePassengers();
	void setReservations(vector<Reservation> res);

};


#endif /* SRC_AIRSHUTTLE_H_ */
