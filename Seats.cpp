#include "Seats.h"


std::ostream& operator<< (std::ostream& out,  Seats& seat) {
	switch (seat.avalaibility) {
	case Avalaible::FREE:
		out << "free"; break;
	case Avalaible::ocuppied:
		out << "ocuppied"; break;
	}
	return out;
}

Seats::Seats(): seatId(rand()) {
	this->avalaibility = Avalaible::FREE;
}

void Seats::setAvalaibility(Avalaible avalaibility) {
	this->avalaibility = avalaibility;
}


Seats::~Seats() {

}
Seats::Seats(int id, Avalaible avalaibilityt): seatId(id), avalaibility(avalaibilityt) {

}
Seats::Seats(Seats& seat): seatId(seat.seatId), avalaibility(seat.avalaibility){
	
}

int Seats::getId() {
	return this->seatId;
}
Avalaible Seats::getAvalaibility() {
	return this->avalaibility;
}

void Seats::operator=(Seats& seat) {
	this->avalaibility = seat.avalaibility;
}
