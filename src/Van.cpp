#include "Van.h"
#include "tools.h"

using namespace std;
/**Construtor of class Van
 *
 */
Van::Van(){};
/**Construtor of class Van
 * @param lPlate license plate of the van
 * @param nPassengers capacity of the van
 */
Van:: Van(string lPlate, int nPassengers){
	this->lPlate=lPlate;
	this->nPassengers=nPassengers;
}
/**Returns the license Plate
 *
 */
string Van:: getLPlate() const {
	return lPlate;
}
/**Modifies the license plate
 * @param lPlate new license plate
 */
void Van:: setLPlate(const string& lPlate) {
	this->lPlate = lPlate;
}
/**Returns the capacity of the van
 *
 */
int Van:: getPassengers() const {
	return nPassengers;
}
/**Modifies the capacity
 * @param nPassengers new capacity
 */
void Van:: setPassengers(int nPassengers) {
	this->nPassengers = nPassengers ;
}
/**Returns the vector of dates of all reservations
 *
 */
const vector<Date> & Van:: getD() const {
	return dates;
}
/**Modifies all the dates of the different reservations
 *
 */
void Van:: setD(const vector<Date> & d) {
	this->dates = d;
}
/**Returns the group of
 *
 */
const vector< vector <Reservation> >& Van:: getReservations() const {
	return reservations;
}
/**Modifies the reservations of the van
 * @param reservation new reservations vector
 */
void  Van:: setReservations(const vector<vector<Reservation> >& reservations) {
	this->reservations = reservations;
}
/**Adds a reservation date
 * @param d new date
 */
void Van:: addDate(Date &d){
	dates.push_back(d);
}
/**Adds a reservation
 * @param r new reservation
 */
void Van:: addReservations(vector<Reservation> r){
	reservations.push_back(r);
}
/**Adds a sorted trip to vector trips
 * @param trip vector of destinations
 */
void Van:: setSortedTrips(vector<string> trip){
	trips.push_back(trip);
}
/**Returns all the sorted trips being done by the van
 *
 */
vector<vector<string> > Van::getTrips() const{
	return trips;
}

/**Returns the index of passenger if exists, if not return -1
 * @param passenger name of the passenger
 */
int Van:: passengerExists(string passenger){
	int index = -1;

	for(int i = 0; i < reservations.size();i++){
		vector<Reservation> group = reservations[i];
		for(int j = 0; j < group.size(); j++){
			if(kmp(group[j].getPassenger().getName(), passenger) != 0){
				index = i;
			}
		}
	}

	return index;
}

/**Returns the reservation of the passenger
 * @param name name of the passenger
 */
Reservation Van:: getReservationByPassenger(string name){
	Reservation r;

	for(int i = 0; i < reservations.size();i++){
		vector<Reservation> group = reservations[i];
		for(int j = 0; j < group.size(); j++){
			if(group[j].getPassenger().getName() == name){
				r = group[j];
			}
		}
	}
	return r;
}
/**Removes a passenger from the van
 * @param index group of the passenger
 */
void Van :: removePassenger(Passenger passenger, int index){
	int i = 0;
	vector<vector<Reservation> > copy = reservations;
	//Search for passenger
	while(i < copy[index].size()){
		if(passenger.getName() == copy[index][i].getPassenger().getName()){
			copy[index].erase(copy[index].begin() + i);
			break;
		}
		i++;
	}

	reservations.clear();
	setReservations(copy);
}
/**Adds a passenger to the van
 * @param passengerReservation reservation of the passenger
 * @param index group to add the passenger
 */
void Van:: addPassenger(Reservation passengerReservation, int index){
	vector<vector<Reservation> > copy = reservations;

	copy[index].push_back(passengerReservation);

	reservations.clear();
	setReservations(copy);
}
/**Checks if the van is full in a given group
 * @param index group
 */
bool Van :: isFull(int index){
	if(nPassengers - reservations[index].size() > 0)
		return true;

	return false;
}
/**Gets the date that the van leaves
 * @param passenger name of the passenger being searched
 */
Date Van:: getDeparture(string passenger){
	int index = passengerExists(passenger);

	return dates[index];
}
/**Returns the most approximate passenger with a given name
 * @param name of the passenger
 */
int Van:: getMostAproxDist(string passenger){
	int num=editDistance(passenger, reservations[0][0].getPassenger().getName());
	int index=0;

	for(int i=1 ; i < reservations.size(); i++) {
		for(int j = 1; j < reservations[i].size(); j++){
			string nametemp = reservations[i][j].getPassenger().getName();
			int numtemp = editDistance(passenger,nametemp);
			if(numtemp < num){
				num = numtemp;

			}
		}
	}
	return num;
}
/*
int Van:: getMostAproxPassenger(string passenger){
	int num=passenger.length();
	int index =-1;

		for(int i=0 ; i < reservations.size(); i++) {
			for(int j = 0; j < reservations[i].size(); j++){
				string nametemp = reservations[i][j].getPassenger().getName();
				int numtemp = editDistance(passenger,nametemp);
				if(numtemp < num || num == -1){
					num = numtemp;
					index = i;
				}
			}
		}
		return index;
}
*/
/**Returns the date of a group
 * @param index index of the group
 */
Date Van:: getIndexDate(int index){
	return dates[index];
}
/**Returns the reservation of a passenger
 * @param index group of the passenger
 * @param nifPassenger NIF of the passenger being searched
 */
Reservation Van:: getIndexReservation(int index, string nifPassenger){
	Reservation r;

	for(int i=0; i < reservations[index].size(); i++){
		if(reservations[index][i].getPassenger().getNif() == nifPassenger){
			r = reservations[index][i];
			break;
		}
	}
	return r;
}

