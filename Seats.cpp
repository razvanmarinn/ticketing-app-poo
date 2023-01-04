#include "Seats.h"

std::istream& operator>>(std::istream& in, Seats& seat) {
	std::cout  << std::endl << " Enter the avalaibility: ";
	int avalaiblity;
	in >> avalaiblity;
	switch (avalaiblity) {
	case Avalaible::FREE:
		std::cout << "free"; break;
	case Avalaible::ocuppied:
		std::cout << "ocuppied"; break;
	}
	return in;
}
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
