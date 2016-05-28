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
				<<" Destination: "<<r[i].getDestination()<< endl;
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

	if(vanIndex == -1){
		cout<<"No reservations in passenger name \n";
	}else{
		Van van = airShuttle.getVans()[vanIndex];
		cout<<"Van: "<<van.getLPlate()<<endl;
		Date date = van.getD()[index];
		cout<<"Date:"<<date.getHour()<<":"<<date.getMinutes()<<endl;
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
	Passenger passenger, passengerFriend;
	Date passengerDate, friendDate;
	Reservation passengerReservation, friendReservation;

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

	cout<<passengerDate.getHour()<<";"<<passengerDate.getMinutes()<<endl;
	cout<<friendDate.getHour()<<";"<<friendDate.getMinutes()<<endl;
	//Checks if they already in the same van
	if(van1.getLPlate()==van2.getLPlate()){
		if(passengerDate.getHour() == friendDate.getHour() && passengerDate.getMinutes() == friendDate.getMinutes()){
			cout<<"You're already traveling with him \n";
		}
		else{
			cout<<"You're in the same Van! I'm going to try \n";
			int passengerMinutes = (passengerReservation.getDate().getHour() * 60) + passengerReservation.getDate().getMinutes();
			int friendMinutes = (friendReservation.getDate().getHour() * 60) + friendReservation.getDate().getMinutes();

			if(friendMinutes - passengerMinutes > 0){
				cout<<"Your friends arrives after you."<<endl;
			}else if(friendMinutes - passengerMinutes < 0){
				if( abs(friendMinutes - passengerMinutes) <= 30){
					cout<<"Your friend arrives before you. We can wait \n";
				}else{
					cout<<"Your friend arrives before you. We can't wait \n";
				}
			}
		}

	}else{
		cout<<"I'm going to try \n";
	}

	mainMenu();
}

void showDates(){

	for(int j = 0 ; j < airShuttle.getVans().size(); j++ ){
		Van van = airShuttle.getVans()[j];
		vector <Date> dates = van.getD();

		for(int i= 0; i < dates.size() ; i++){
			cout<<dates[i].getHour()<<":"<<dates[i].getMinutes()<<";";
		}
		cout<<endl;
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
	cout<<"8- Show dates \n";
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
	case 8:
		showDates();
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
	readReservations(airShuttle);
	readVans(airShuttle);
	airShuttle.distributePassengers();
	for(unsigned int i=0; i < airShuttle.getVans().size(); i++ )
		airShuttle.sortDistributions(g,i+1);
	mainMenu();
	return 0;
}
