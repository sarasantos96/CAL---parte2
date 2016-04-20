#ifndef SRC_EXCEPTIONS_H_
#define SRC_EXCEPTIONS_H_

#include "Reservation.h"

class DuplicateReservationException{
	Reservation reservation;
public:
	DuplicateReservationException(Reservation r){reservation=r;}
	Reservation getDuplicateReservation(){return reservation;}
};

class InexistentReservationException{
	Reservation reservation;
public:
	InexistentReservationException(Reservation r){reservation=r;}
	Reservation getInexistentReservation(){return reservation;}
};

class DuplicateVanException{
	Van van;
public:
	DuplicateVanException(Van v){ van= v;}
	Van getDuplicateVan(){ return van;}
};

class InexistentVanException{
	Van van;
public:
	InexistentVanException(Van v){ van= v;}
	Van getInexistentVan(){ return van;}
};


#endif /* SRC_EXCEPTIONS_H_ */
