#include"Location.h"

std::ostream& operator<<(std::ostream& out,  location& location) {
	out << std::endl << "Locatiom ID :" << location.getId();
	out << std::endl << "Number of seats " << location.getNumberOfSeats();
	out << std::endl << "Avalaiblity of the seats(1 = true , 0 = false )";
	for (auto i = 0; i < location.numberOfSeats; i++) {
		out << std::endl << "seat " << i + 1 << " availability " << location.seats[i].getAvalaibility() << " and id of the seat -> " << location.seats[i].getId();
	}
	return out;
}
location::~location() {

}

void location::operator=(location& location) {
	this->numberOfSeats = location.numberOfSeats;
}

location::location() {

}
location::location(location& location):id(location.id), numberOfSeats(location.numberOfSeats){
	this->seats = new Seats[location.numberOfSeats];
	for (auto i = 0; i < location.numberOfSeats; i++) {
		this->seats[i] = location.seats[i];
	}

}
location::location(int id,int numberOfSeats,  Seats* seats):id(id), numberOfSeats(numberOfSeats) {
	this->seats = new Seats[numberOfSeats ];
	for (int i = 0; i < numberOfSeats ; i++) {
		this->seats[i] = seats[i];
	}
}
void location::getEvents() {
	std::cout<<"to be implemented";
}
int location::getNumberOfSeats() {
	return this->numberOfSeats;
}
void location::print() {
	std::cout << std::endl << "Locatiom ID :" << this->getId();
	std::cout << std::endl << "Number of seats " << this->getNumberOfSeats();
	std::cout << std::endl << "Avalaiblity of the seats(1 = true , 0 = false )";
	for (auto i = 0; i < this->numberOfSeats; i++) {
		std::cout << std::endl << "seat " << i+1 << " availability " << this->seats[i].getAvalaibility() << " and id of the seat -> " << this->seats[i].getId();
	}
}

int location::getId() {
	return this->id;
}
Seats location::getSeats() {
	return this->seats[0];
}