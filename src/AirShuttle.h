#ifndef SRC_AIRSHUTTLE_H_
#define SRC_AIRSHUTTLE_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "Reservation.h"
#include "Van.h"
#include "Passenger.h"
#include "tools.h"

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
	vector<Reservation> getReservationByDestination(string destination);
	vector<Reservation> getReservationByDate(Date &d);
	void setReservations(vector<Reservation> res);
	void distributePassengers();
	void sortDistributions(Graph<Node,Road> &g, unsigned int vanNumber);
	vector<Reservation> sortTrips(vector<Node> path, Date pDate);
	void removePassengerFromVan(Passenger passenger, int van, int index);
	void setVans(const vector<Van>& vans);
	void addPassengerToVan(Reservation passengerReservation, int van, int index);
	int vanAproxPassenger(string passenger);
	int getPassengerVan(string passenger);
	void getPassengerInfo(Van &van, Reservation &r, Date &date);
	vector<Reservation> reservationsToAdress(string adress);
};


#endif /* SRC_AIRSHUTTLE_H_ */
