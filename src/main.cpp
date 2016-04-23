#include "main.h"

using namespace std;

#define RESERVATIONS "Reservations.txt"
#define VANS "Vans.txt"

AirShuttle airShuttle;
/*
void changePassengerNIF(){
	string oldNif, newNif;

	cout<<"Current NIF: \n";
	cin>>oldNif;
	cout<<"New Nif: \n";
	cin>> newNif;

	try{
		airShuttle.changePassengerNIF(oldNif, newNif);
	}catch(InexistentPassengerException &e){
		cout<< "Passenger does not exist\n";
		passengerMenu();
	}
	passengerMenu();
}

void changePassengerName(){
	string oldName, newName;

	cout<<"Current Name: \n";
	cin>>oldName;
	cout<<"New Name: \n";
	cin>> newName;

	try{
		airShuttle.changePassengerName(oldName, newName);
	}catch(InexistentPassengerException &e){
		cout<< "Passenger does not exist\n";
		passengerMenu();
	}
	passengerMenu();
}

void passengerMenu(){
	cout<<"1- Change Passenger NIF \n";
	cout<<"2- Change Passenger name \n";
	cout<<"3- Main Menu \n";

	int option;
	cin>> option;

	switch(option){
	case 1:
		changePassengerNIF();
		break;
	case 2:
		changePassengerName();
		break;
	case 3:
		mainMenu();
		break;
	default:
		cout<<"Invalid option. Insert new one\n";
		passengerMenu();
		break;
	}
}

void addReservation(){
	int day, month, year, hour, min, price, aDay, aMonth, aYear, aHour, aMin;
	string name, destination, nif;

	cout<<"Date of Reservation: \n";
	cout<<"Day: ";
	cin>>day;
	cout<<"Month: ";
	cin>>month;
	cout<<"Year: ";
	cin>>year;
	cout<<"Hour: ";
	cin>>hour;
	cout<<"Minute: ";
	cin>>min;
	Date dRerservation = Date(day, month, year, hour, min);

	cout<<"Passenger's name: ";
	cin>>name;
	cout<<"Passenger's NIF: ";
	cin>>nif;
	Passenger p= Passenger(name, nif);

	cout<<"Date of Passenger's arrival: \n";
	cout<<"Day: ";
	cin>>day;
	cout<<"Month: ";
	cin>>month;
	cout<<"Year: ";
	cin>>year;
	cout<<"Hour: ";
	cin>>hour;
	cout<<"Minute: ";
	cin>>min;
	Date dArrival= Date(aDay, aMonth, aYear, aHour, aMin);

	cout<<"Destination: ";
	cin>>destination;

	cout<<"Price: ";
	cin>>price;

	int id= 0;

	Reservation r = Reservation(id,dRerservation, p, price, dArrival, destination);

	try{
		airShuttle.addReservation(r);
	}catch(DuplicateReservationException &e){
		cout<< "Reservation already exists! \n";
		reservationMenu();
	}
	reservationMenu();
}


void removeReservation(){
	int id;

	cout<<"Reservation ID: ";
	cin>>id;

	try{
		airShuttle.removeReservation(id);
	}catch(InexistentReservationException &e){
		cout<< "Reservation with ID number "<<id<<" doesn't exist \n";
		reservationMenu();
	}
	reservationMenu();
}

void getReservationsByDate(){
	int day, month, year, hour, min;

	cout<<"Date of Reservation: \n";
	cout<<"Day: ";
	cin>>day;
	cout<<"Month: ";
	cin>>month;
	cout<<"Year: ";
	cin>>year;

	Date d = Date(day, month, year, 0, 0);

	vector<Reservation> r = airShuttle.getReservationByDate(d);

	if(r.size()== 0 ){
		cout<<"No reservations on this date \n";
		reservationMenu();
	}

	for(unsigned int i=0; i< r.size(); i++){
		cout<<"ID: "<<r[i].getId()<<" Passenger: "<<r[i].getPassenger().getName()<<" "<<r[i].getPassenger().getNif()<<
				" Date: "<<r[i].getDate().getDay()<<"/"<<r[i].getDate().getMonth()<<"/"<<r[i].getDate().getYear()<<" "<<
				r[i].getDate().getHour()<<":"<<r[i].getDate().getMinutes()<<" Price: "<<r[i].getPrice()<<" Arrival: "<<
				r[i].getArrival().getDay()<<"/"<<r[i].getArrival().getMonth()<<"/"<<r[i].getArrival().getYear()<<" "<<
				r[i].getArrival().getHour()<<":"<<r[i].getArrival().getMinutes()<<" Destination: "<<r[i].getDestination()
				<<endl;
	}
	reservationMenu();
}

void getReservationsByPassenger(){
	string name;
	string nif;

	cout<<"Passenger's name: ";
	cin>> name;
	cout<<"Passenger's nif: ";
	cin>>nif;

	Passenger p= Passenger(name, nif);
	vector<Reservation> r= airShuttle.getReservationByPassenger(p);

	if(r.size()== 0 ){
		cout<<"No reservations for this passenger \n";
		reservationMenu();
	}

	for(unsigned int i=0; i< r.size(); i++){
		cout<<"ID: "<<r[i].getId()<<"Passenger: "<<r[i].getPassenger().getName()<<" "<<r[i].getPassenger().getNif()<<
				"Date: "<<r[i].getDate().getDay()<<"/"<<r[i].getDate().getMonth()<<"/"<<r[i].getDate().getYear()<<" "<<
				r[i].getDate().getHour()<<":"<<r[i].getDate().getMinutes()<<"Price: "<<r[i].getPrice()<<"Arrival: "<<
				r[i].getArrival().getDay()<<"/"<<r[i].getArrival().getMonth()<<"/"<<r[i].getArrival().getYear()<<" "<<
				r[i].getArrival().getHour()<<":"<<r[i].getArrival().getMinutes()<<"Destination: "<<r[i].getDestination()
				<<endl;
	}
	reservationMenu();
}

void reservationMenu(){
	cout<<"1- Add Reservation \n";
	cout<<"2- Remove Reservation \n";
	cout<<"3- Get Reservations by Date \n";
	cout<<"4- Get Reservations by Passenger \n";
	cout<<"5- Main Menu \n";

	int option;
	cin>> option;

	switch(option){
	case 1:
		addReservation();
		break;
	case 2:
		removeReservation();
		break;
	case 3:
		getReservationsByDate();
		break;
	case 4:
		getReservationsByPassenger();
		break;
	case 5:
		mainMenu();
		break;
	default:
		cout<<"Invalid option. Insert new one\n";
		reservationMenu();
	}
}

void addVan(){
	string lp;
	int cap;

	cout<<"License Plate: ";
	cin>>lp;
	cout<<"Capacity: ";
	cin>>cap;
	Van v= Van(lp,cap);

	try{
		airShuttle.addVan(v);
	}catch(DuplicateVanException &e){
		cout<<"This van already exists \n";
		vanMenu();
	}
	vanMenu();
}

void removeVan(){
	string lp;
	int cap;

	cout<<"License Plate: ";
	cin>>lp;
	cout<<"Capacity: ";
	cin>>cap;
	Van v= Van(lp,cap);

	try{
		airShuttle.removeVan(v);
	}catch(InexistentVanException &e){
		cout<<"This van does not exists \n";
		vanMenu();
	}
	vanMenu();
}

void vanMenu(){
	cout<<"1- Add Van\n";
	cout<<"2- Remove Van \n";
	cout<<"3- Main Menu \n";

	int option;
	cin>>option;

	switch(option){
	case 1:
		addVan();
		break;
	case 2:
		removeVan();
		break;
	case 3:
		mainMenu();
		break;
	default:
		cout<<"Invalid option. Insert new one\n";
		vanMenu();
		break;
	}
}

void mainMenu(){
	cout<<"1- Passenger options \n";
	cout<<"2- Reservation options \n";
	cout<<"3- Van options \n";
	cout<<"5- Read Reservations \n";
	cout<<"4- Exit \n";

	int option;

	cin>> option;
	switch(option){
	case 1:
		passengerMenu();
		break;
	case 2:
		reservationMenu();
		break;
	case 3:
		vanMenu();
		break;
	case 4:
		return;
	case 5:
		readReservations();
		break;
	default:
		cout<<"Invalid option. Insert new one \n";
		mainMenu();
		break;
	}
}*/

void readReservations(){
	ifstream infile;
	string line;
	infile.open(RESERVATIONS);
	int id,Hour, Min, Day;
	string name, destination,nif;

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

		Passenger p= Passenger(name,nif);
		Date d= Date(Hour, Min);
		Reservation r= Reservation(id,d,p,destination);
		airShuttle.addReservation(r);
	}

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

//
//int main(){
//	airShuttle = AirShuttle();
	/*mainMenu();*/
//	readReservations();
//	vector<Reservation> r = airShuttle.getReservations();

//	for(unsigned int i=0; i< r.size(); i++){
//		cout<< r[i].getId()<<" "<<r[i].getPassenger().getName()<<" "<<r[i].getPassenger().getNif()<<" "<<
//				r[i].getDate().getHour()<<" "<<r[i].getDate().getMinutes()<<" "<<r[i].getDestination()<<endl;
//	}
	//readVans();
	/*vector<Van> v= airShuttle.getVans();
	for(int i=0; i< v.size();i++){
		cout<<v[i].getLPlate()<<" "<<v[i].getPassengers()<<endl;
	}*/

//	return 0;
//}
