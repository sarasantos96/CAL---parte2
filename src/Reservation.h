#ifndef SRC_RESERVATION_H_
#define SRC_RESERVATION_H_

#include <iostream>
#include "Date.h"
#include "Passenger.h"

using namespace std;

class Reservation{
private:
	Date date;
	Passenger passenger;
	int price;
	Date arrival;
	string destination;
public:
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
};



#endif
