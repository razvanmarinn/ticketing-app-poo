#include "FotballTicket.h"


FotballTicket::FotballTicket() {
}

FotballTicket::FotballTicket(FotballTicket& ticket) : Ticket(ticket.getPrice(), ticket.event), zone(ticket.zone) {
}

FotballTicket::FotballTicket(Event event, FotballZones zone) : Ticket(0, event) {
	this->zone = zone;
	if (zone == 0) {
		this->setPrice(350);
	}
	this->setPrice(500);

}

bool FotballTicket::checkTicket(int id) {
	if (this->ticketId == id) {
		return true;
	}
	else {
		return false;
	}
}
FotballZones FotballTicket::getZone() {
	return this->zone;
}


void FotballTicket::print() {
	std::cout << std::endl << "Ticket id " << this->getId();
	std::cout << std::endl << "Ticket event " << this->getNameOfTheEvent();
	std::cout << std::endl << "Ticket price " << this->getPrice();
	std::cout << std::endl << "Ticket zone ";
	if (this->getZone() == 0) {
		std::cout << "Stand1";
	}
	else {
		std::cout << "Stand2";
	}
	std::cout << std::endl << "======================";
}

void FotballTicket::write(std::ostream& out_stream) {
	out_stream << "FotballTicket" << std::endl;
	out_stream << "Id of the ticket : " << this->getId() << std::endl;
	out_stream << "Event attended : " << this->getNameOfTheEvent() << std::endl;
	out_stream << "Price of the ticket : " << this->getPrice() << std::endl;
	out_stream << "Zone of the ticket : " << this->getZone() << std::endl;
	out_stream << "Avalaibility :" << this->getAvalaiblity() << std::endl;
	out_stream << std::endl;
}

FotballTicket* FotballTicket::read(std::istream& in_stream) {
	int year, month, day;
	in_stream >> year >> month >> day;
	Date date(year, month, day);

	std::string name;
	in_stream >> name;
	const char* name_char = name.c_str();

	int duration;
	in_stream >> duration;

	int number_of_seats;
	in_stream >> number_of_seats;
	Seats* seats = new Seats[number_of_seats];
	for (int i = 0; i < number_of_seats; i++) {

		int seat_number;
		in_stream >> seat_number;

		int seat_status;
		in_stream >> seat_status;
		Seats seat(seat_number, (Avalaible)seat_status);
		seats[i] = seat;
	}

	int zone;
	in_stream >> zone;
	location loc(number_of_seats, number_of_seats, seats);
	Event event(date, name_char, duration, loc, number_of_seats);
	FotballTicket* fotbalticket = new FotballTicket(event, (FotballZones)zone);
	fotbalticket->print();
	return fotbalticket;
}

std::istream& operator>>(std::istream& in, FotballTicket* ticket) {

	std::cout << "Create fotball ticket" << std::endl;
	Date date;
	std::cin >> date;
	std::cout << "Enter the event name: " << std::endl;
	std::string name;
	std::cin >> name;
	const char* name_char = name.c_str();
	std::cout << "Enter the duration: " << std::endl;
	int duration;
	std::cin >> duration;
	std::cout << "Enter the number of seats: " << std::endl;
	int number_of_seats;
	std::cin >> number_of_seats;
	Seats* seats = new Seats[number_of_seats];
	for (int i = 0; i < number_of_seats; i++) {
		std::cout << "Enter the seat number: " << std::endl;
		int seat_number;
		std::cin >> seat_number;
		std::cout << "Enter the seat status: " << std::endl;
		int seat_status;
		std::cin >> seat_status;
		Seats seat(seat_number, (Avalaible)seat_status);
		seats[i] = seat;
	}
	std::cout << "Enter the zone: " << std::endl;
	int zone;
	std::cin >> zone;

	location loc(number_of_seats, number_of_seats, seats);
	Event event(date, name_char, duration, loc, number_of_seats);
	FotballTicket* fotbalticket = new FotballTicket(event, (FotballZones)zone);
	fotbalticket->print();

	return in;


}