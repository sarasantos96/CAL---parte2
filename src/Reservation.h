#ifndef SRC_RESERVATION_H_
#define SRC_RESERVATION_H_

#include <iostream>

using namespace std;

class Reservation{
private:
	int date;
	Passenger passenger;
	int price;
	Date arrival;
	string destination;
public:
	Reservation(int date, Passenger passenger, int price, Date arrival, string destination);
	const Date& getArrival() const;
	void setArrival(const Date& arrival);
	int getDate() const;
	void setDate(int date);
	const string& getDestination() const;
	void setDestination(const string& destination);
	const Passenger& getPassenger() const;
	void setPassenger(const Passenger& passenger);
	int getPrice() const;
	void setPrice(int price);
};



#endif
