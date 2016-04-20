#ifndef SRC_RESERVATION_H_
#define SRC_RESERVATION_H_

#include <iostream>
#include "Date.h"
#include "Passenger.h"

using namespace std;



class Reservation{
private:
	int id;
	Date date;
	Passenger passenger;
	int price;
	Date arrival;
	string destination;
public:
	Reservation();
	Reservation(Date date, Passenger passenger, int price, Date arrival, string destination);
	const Date& getArrival() const;
	void setArrival(const Date& arrival);
	const Date& getDate() const;
	void setDate(Date date);
	const string& getDestination() const;
	void setDestination(const string& destination);
	const Passenger& getPassenger() const;
	void setPassenger(const Passenger& passenger);
	int getPrice() const;
	void setPrice(int price);
	int getId() const;
	bool operator ==(const Reservation &r2){
		if(id == r2.getId())
			return true;
		return false;
	}
};

#endif
