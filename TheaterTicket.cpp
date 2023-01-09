#include "TheaterTicket.h"


TheaterTicket::TheaterTicket() {
}

TheaterTicket::TheaterTicket(Event event, TheaterZones zone) : Ticket(0, event) {
	this->zone = zone;
	switch (zone) {
	case TheaterZones::Box:
		this->setPrice(1000);
	case TheaterZones::Category1:
		this->setPrice(700); break;
	case TheaterZones::Category2:
		this->setPrice(500); break;
	}

}
bool TheaterTicket::checkTicket(int id) {
	if (this->ticketId == id) {
		return true;
	}
	else {
		return false;
	}
}
TheaterZones TheaterTicket::getZone() {
	return this->zone;
}

void TheaterTicket::print() {
	std::cout << std::endl << "Ticket id " << this->getId();
	std::cout << std::endl << "Ticket event " << this->getNameOfTheEvent();
	std::cout << std::endl << "Ticket price " << this->getPrice();
	std::cout << std::endl << "Ticket zone ";
	if (this->getZone() == 0) {
		std::cout << "Box";
	}
	else if (this->getZone() == 1) {
		std::cout << "Category1";
	}
	else {
		std::cout << "Category2";
	}
	std::cout << std::endl << "======================";

}
void TheaterTicket::write(std::ostream& out_stream) {
	out_stream << "TheaterTicket" << std::endl;
	out_stream << "Id of the ticket : " << this->getId() << std::endl;
	out_stream << "Event attended : " << this->getNameOfTheEvent() << std::endl;
	out_stream << "Price of the ticket : " << this->getPrice() << std::endl;
	out_stream << "Zone of the ticket : " << this->getZone() << std::endl;
	out_stream << "Avalaibility :" << this->getAvalaiblity() << std::endl;
	out_stream << std::endl;
}

std::istream& operator>>(std::istream& in, TheaterTicket* ticket) {
	std::cout << "Enter the event name: ";
	Event event;
	in >> event;

	std::cout << "Enter the price: ";
	int price;
	in >> price;
	ticket->setPrice(price);
	bool avalaible;
	std::cout << "Enter avalaibility ";
	in >> avalaible;
	ticket->avalaible = avalaible;
	std::cout << "Enter the zone: ";
	int zone;
	in >> zone;
	ticket->zone = static_cast<TheaterZones>(zone);

	return in;
}