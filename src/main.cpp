#include "main.h"
#include "FileReader.h"
#include <algorithm>

using namespace std;

#define RESERVATIONS "Reservations.txt"
#define VANS "Vans.txt"


AirShuttle airShuttle;

void diplayReservations() {
	vector <Reservation> r = airShuttle.getReservations();

	for(unsigned int i=0; i < r.size(); i++){
		cout << "ID: "<< r[i].getId()<< "; Passenger:  "<<r[i].getPassenger().getName()<< " "<<r[i].getPassenger().getNif()
				<<"; Arrival: "<<r[i].getDate().getHour()<<":"<<r[i].getDate().getMinutes()
				<<"Destination: "<<r[i].getDestination()<< endl;
	}
	mainMenu();
}

void displayVans(){
	vector<Van> v = airShuttle.getVans();
	for(unsigned int i=0; i < v.size(); i++){
		cout<<"License Plate: "<<v[i].getLPlate()<<" Capacity: "<<v[i].getPassengers()<<endl;
	}
	mainMenu();
}

void displayTrips(){
	mainMenu();
}

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

void mainMenu(){
	cout<<"1- Show all reservations \n";
	cout<<"2- Show all vans \n";
	cout<<"3- Show passenger groups \n";
	cout<<"4- Show trips \n";
	cout<<"5- Exit \n";

	int option;

	cin>> option;
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
		return;
	default:
		cout<<"Invalid option. Insert new one \n";
		mainMenu();
		break;
	}
}

void readReservations(){
	ifstream infile;
	string line;
	infile.open(RESERVATIONS);
	int id,Hour, Min, Day;
	string name, destination,nif;
	vector <Reservation> res;

	while(getline(infile,line)){
		stringstream linestream(line);
		string data;

		linestream >> id;
		getline(linestream, data, ';');
		getline(linestream, name, ';');
		getline(linestream, nif, ';');
		linestream >> Hour;
		getline(linestream, data, ';');
		linestream >> Min;
		getline(linestream, destination, ';');
		linestream >> destination;

		Passenger p= Passenger(name,nif);
		Date d= Date(Hour, Min);
		Reservation r= Reservation(id,d,p,destination);
		res.push_back(r);
	}

	sort(res.begin(),res.end());
	airShuttle.setReservations(res);
	infile.close();
}

void readVans(){
	ifstream infile;
	string line;
	infile.open(VANS);

	while(getline(infile,line)){
		stringstream linestream(line);
		stringstream linestream2(line);
		string data;
		string lp;
		int cap;

		getline(linestream, lp, ';');  // read up-to the first ; (discard ;).
		getline(linestream2, data, ';');
		linestream2 >> cap;

		Van v= Van(lp,cap);
		airShuttle.addVan(v);
	}
	infile.close();
}


int main(){
	Graph<Node,Road> g;
	loadGraph(g);
	airShuttle = AirShuttle();
	readReservations();
	readVans();
	airShuttle.distributePassengers();
	/*airShuttle.sortDistributions(g,1);*/
	mainMenu();
	return 0;
}
