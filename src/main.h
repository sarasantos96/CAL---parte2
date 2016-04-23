#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <iostream>
#include "AirShuttle.h"
#include "Passenger.h"
#include "Reservation.h"
#include "Van.h"
#include "Date.h"
#include "Exceptions.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void addPassenger();

void removePassenger();

void changePassengerNIF();

void changePassengerName();

void passengerMenu();

void addReservation();

void removeReservation();

void getReservationsByDate();

void getReservationsByPassenger();

void reservationMenu();

void addVan();

void removeVan();

void vanMenu();

void readReservations();

void readVans();

void mainMenu();

int main();
#endif /* SRC_MAIN_H_ */
