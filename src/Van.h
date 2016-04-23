#ifndef SRC_VAN_H_
#define SRC_VAN_H_

#include <iostream>
#include "Reservation.h"
#include <vector>

using namespace std;

class Van{
private:
	string lPlate;
	int nPassengers;
	vector <Reservation> reservations;
	Date d;

public:
	Van();
	Van(string lPlate, int nPassengers);
	string getLPlate() const;
	void setLPlate(const string& lPlate);
	int getPassengers() const;
	void setPassengers(int nPassengers);
	const Date& getD() const ;
	void setD(const Date& d);
	const vector<Reservation>& getReservations() const;
	void setReservations(const vector<Reservation>& reservations);
	void addReservation(Reservation r);
	bool operator ==(const Van &v2){
			if(lPlate == v2.getLPlate())
				return true;
			return false;
		}
	vector<Reservation> getReservations();
	void setReservations(vector<Reservation> res);
};


#endif
