#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_
#include <iostream>

using namespace std;

class Passenger{
private:
	string name;
	int nif;
public:
	Passenger();
	Passenger(string name, int nif);
	string getName() const;
	void setName(const string name);
	int getNif() const;
	void setNif(int nif);
	friend bool operator ==(const Passenger &p1, const Passenger &p2){
		if((p1.getName() == p2.getName()) && (p1.getNif() == p2.getNif()))
			return true;
		return false;
	}
};





#endif
