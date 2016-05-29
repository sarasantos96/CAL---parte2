#include "Van.h"

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

void pre_kmp(string pattern, vector<int> & prefix)
{
	int m=pattern.length();
	prefix[0]=-1;
	int k=-1;
	for (int q=1; q<m; q++) {
		while (k>-1 && pattern[k+1]!=pattern[q])
			k = prefix[k];
		if (pattern[k+1]==pattern[q]) k=k+1;
		prefix[q]=k;
	}
}

int kmp(string text, string pattern)
{
	int num=0;
	int m=pattern.length();
	vector<int> prefix(m);
	pre_kmp(pattern, prefix);

	int n=text.length();

	int q=-1;
	for (int i=0; i<n; i++) {
		while (q>-1 && pattern[q+1]!=text[i])
			q=prefix[q];
		if (pattern[q+1]==text[i])
			q++;
		if (q==m-1) {
			num++;
			q=prefix[q];
		}
	}
	return num;
}

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

void Van:: addPassenger(Reservation passengerReservation, int index){
	vector<vector<Reservation> > copy = reservations;

	copy[index].push_back(passengerReservation);

	reservations.clear();
	setReservations(copy);
}

bool Van :: isFull(int index){
	if(nPassengers - reservations[index].size() > 0)
		return true;

	return false;
}

Date Van:: getDeparture(string passenger){
	int index = passengerExists(passenger);

	return dates[index];
}

int editDistance(string pattern, string text)
{
	int n=text.length();
	vector<int> d(n+1);
	int old,neww;
	for (int j=0; j<=n; j++)
		d[j]=j;
	int m=pattern.length();
	for (int i=1; i<=m; i++) {
		old = d[0];
		d[0]=i;
		for (int j=1; j<=n; j++) {
			if (pattern[i-1]==text[j-1]) neww = old;
			else {
				neww = min(old,d[j]);
				neww = min(neww,d[j-1]);
				neww = neww +1;
			}
			old = d[j];
			d[j] = neww;
		}
	}
	return d[n];
}

int Van:: getMostAproxDist(string passenger){
	int num=passenger.length();

	for(int i=0 ; i < reservations.size(); i++) {
		for(int j = 0; j < reservations[i].size(); j++){
			string nametemp = reservations[i][j].getPassenger().getName();
			int numtemp = editDistance(passenger,nametemp);
			if(numtemp < num || num == -1){
				num = numtemp;
			}
		}
	}
	return num;
}

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

Date Van:: getIndexDate(int index){
	return dates[index];
}

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

