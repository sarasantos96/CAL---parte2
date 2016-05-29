#include "main.h"
#include "FileReader.h"

using namespace std;

AirShuttle airShuttle;

/**Display all the reservations
 *
 */
void diplayReservations() {
	vector <Reservation> r = airShuttle.getReservations();

	for(unsigned int i=0; i < r.size(); i++){
		cout << "ID: "<< r[i].getId()<< "; Passenger:  "<<r[i].getPassenger().getName()<< " "<<r[i].getPassenger().getNif()
				<<"; Arrival: "<<r[i].getDate().getHour()<<":"<<r[i].getDate().getMinutes()
				<<" Hotel: "<<r[i].getDestination()<<"Destination: "<<r[i].getMorada()<< endl;
	}
	mainMenu();
}
/**Display all the vans
 *
 */
void displayVans(){
	vector<Van> v = airShuttle.getVans();
	for(unsigned int i=0; i < v.size(); i++){
		cout<<"License Plate: "<<v[i].getLPlate()<<" Capacity: "<<v[i].getPassengers()<<endl;
	}
	mainMenu();
}
/**Display all the trips by van, date and order of route
 *
 */
void displayTrips(){
	vector <Van> v = airShuttle.getVans();
	for (unsigned int i=0; i< v.size(); i++){
		cout<<"Van "<<v[i].getLPlate()<<endl;
		vector < vector <string> > trips = v[i].getTrips();
		vector < Date > dates= v[i].getD();
		for(unsigned int j=0; j < trips.size(); j++){
			cout<<dates[j].getHour()<<":"<<dates[j].getMinutes()<<"- ";
			for(unsigned int k=0; k < trips[j].size(); k++){
				if(k == trips[j].size() -1)
					cout<<trips[j][k];
				else
					cout<<trips[j][k]<<"->";
			}
			cout<<endl;
		}

	}

	mainMenu();
}
/**Display all the groups of passengers that travel together
 *
 */
void displayGroups(){
	vector <Van> v = airShuttle.getVans();

	for(unsigned int i=0; i< v.size(); i++){
		cout<<"Van: "<<v[i].getLPlate()<<endl;
		vector <vector <Reservation> > groups = v[i].getReservations();
		for(unsigned int j=0; j < groups.size(); j++ ){
			for(unsigned int k=0; k < groups[j].size(); k++){
				cout<<groups[j][k].getPassenger().getName()<<"; ";
			}
			cout<<endl;
		}
	}
	mainMenu();
}
void consultReservation(){
	//Name of passenger
	string name;
	cout<<"Passenger's name: ";
	cin.ignore(10,'\n');
	getline(cin,name);

	int index = airShuttle.vanAproxPassenger(name);

	if(index == -1){
		cout<<"No reservations in passenger name \n";
	}else{
		Van van = airShuttle.getVans()[index];
		int subIndex = van.getMostAproxDist(name);
		Date date = van.getIndexDate(subIndex);
		//Reservation r ;
		//cout<<"Name: "<<r.getPassenger().getName()<<endl;
		cout<<"Van: "<<van.getLPlate()<<endl;
		cout<<"Hour of departure: "<<date.getHour()<<":"<<date.getMinutes()<<endl;
	}

	mainMenu();
}

void travelWithFriend(){
	string name, friendName;

	cin.ignore(10, '\n');
	cout<<"Your name: ";
	getline(cin, name);
	cin.ignore(10,'\n');
	cout<<"Friend name: ";
	getline(cin,friendName);

	//cin.ignore(10,'\n');
	Van van1, van2;
	Date passengerDate, friendDate;
	Reservation passengerReservation, friendReservation;
	bool change= false;

	//Passenger information
	int vanIndex = -1;
	int index =-1;
	for(int i = 0; i < airShuttle.getVans().size(); i++){
		Van van =  airShuttle.getVans()[i];
		if(van.passengerExists(name) != -1){
			index = van.passengerExists(name);
			vanIndex = i;
			break;
		}
	}

	if(vanIndex != -1){
		van1 = airShuttle.getVans()[vanIndex];
		passengerDate = van1.getD()[index];
		passengerReservation = van1.getReservationByPassenger(name);
	}else{
		cout<<"Your name is not on the passenger list \n";
	}

	//Friend information
	int friendVanIndex = -1;
	int friendIndex =-1;
	for(int i = 0; i < airShuttle.getVans().size(); i++){
		Van van =  airShuttle.getVans()[i];
		if(van.passengerExists(friendName) != -1){
			friendIndex = van.passengerExists(friendName);
			friendVanIndex = i;
			break;
		}
	}
	if(friendVanIndex != -1){
		van2 = airShuttle.getVans()[friendVanIndex];
		friendDate = van2.getD()[index];
		friendReservation = van2.getReservationByPassenger(friendName);
	}else{
		cout<<"Your friend's name is not on the passenger list \n";
	}

	if(van1.getLPlate()==van2.getLPlate() && passengerDate == friendDate){
			cout<<"You're already traveling with him \n";
	}else{
		int passengerMinutes = (passengerReservation.getDate().getHour() * 60) + passengerReservation.getDate().getMinutes();
		int friendMinutes = (friendReservation.getDate().getHour() * 60) + friendReservation.getDate().getMinutes();

		if(friendMinutes - passengerMinutes > 0){
			cout<<"Your friends arrives after you.You wait for him"<<endl;
			change = true;
		}else if(friendMinutes - passengerMinutes < 0){
			if( abs(friendMinutes - passengerMinutes) <= 30){
				cout<<"Your friend arrives before you. We can wait \n";
				change = true;
			}else{
				cout<<"Your friend arrives before you. We can't wait \n";
			}
		}
	}

	if(change){
		cout<<"Removing from your van... \n";
		airShuttle.removePassengerFromVan(passengerReservation.getPassenger(),vanIndex, index);
		airShuttle.addPassengerToVan(passengerReservation, friendVanIndex,friendIndex);
		cout<<"Your reservation has been successfully changed \n";
	}else{
		cout<<"You're reservation hasn't been changed \n";
	}

	mainMenu();
}

/**Main menu Function
 *
 */
void mainMenu(){
	cout<<"1- Show all reservations \n";
	cout<<"2- Show all vans \n";
	cout<<"3- Show passenger groups \n";
	cout<<"4- Show trips \n";
	cout<<"5- Consult passenger reservation \n";
	cout<<"6- Travel with friend \n";
	cout<<"7- Exit \n";

	int option;

	cin>> option;
	;
	switch(option){
	case 1:
		diplayReservations();
		break;
	case 2:
		displayVans();
		break;
	case 3:
		displayGroups();
		break;
	case 4:
		displayTrips();
		break;
	case 5:
		consultReservation();
		break;
	case 6:
		travelWithFriend();
		break;
	case 7:
		return;
	default:
		cout<<"Invalid option. Insert new one \n";
		mainMenu();
		break;
	}
}

/**Main Funtion
 *
 */
int main(){
	Graph<Node,Road> g;
	loadGraph(g);
	airShuttle = AirShuttle();
	readReservations(airShuttle, g);
	readVans(airShuttle);
	airShuttle.distributePassengers();
	for(unsigned int i=0; i < airShuttle.getVans().size(); i++ )
		airShuttle.sortDistributions(g,i+1);
	mainMenu();
	return 0;
}
