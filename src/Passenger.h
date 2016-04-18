#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_
#include <iostream>

using namespace std;

class Passenger{
private:
	string name;
	int nif;
public:
	Passenger(string name, int nif);
	string getName() const;
	void setName(const string name);
	int getNif() const;
	void setNif(int nif);

};





#endif
