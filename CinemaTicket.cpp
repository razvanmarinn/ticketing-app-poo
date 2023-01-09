#include "CinemaTicket.h"



CinemaTicket::CinemaTicket(CinemaTicket& other) :Ticket(other.getPrice(), other.event), zone(other.zone) {
}

CinemaTicket::CinemaTicket() {
}

CinemaTicket::CinemaTicket(Event event, CinemaZones zone) : Ticket(0, event) {
	this->zone = zone;
	if (zone == 1) {
		this->setPrice(3500);
	}
	this->setPrice(5000);

};

bool CinemaTicket::checkTicket(int id) {
	if (this->ticketId == id) {
		return true;
	}
	else {
		return false;
	}
}

CinemaZones CinemaTicket::getZone() {
	return this->zone;
}

void CinemaTicket::print() {
	std::cout << std::endl << "Ticket id " << this->getId();
	std::cout << std::endl << "Ticket event " << this->getNameOfTheEvent();
	std::cout << std::endl << "Ticket price " << this->getPrice();
	std::cout << std::endl << "Ticket zone ";
	if (this->getZone() == 0) {
		std::cout << "VIP";
	}
	else {
		std::cout << "Normal";
	}
	std::cout << std::endl << "======================";
}


void CinemaTicket::write(std::ostream& out_stream) {
	out_stream << "CinemaTicket" << std::endl;
	out_stream << "Id of the ticket : " << this->getId() << std::endl;
	out_stream << "Event attended : " << this->getNameOfTheEvent() << std::endl;
	out_stream << "Price of the ticket : " << this->getPrice() << std::endl;
	out_stream << "Zone of the ticket : "<<this->getZone() << std::endl;
	out_stream << "Avalaibility :" << this->getAvalaiblity() << std::endl;
	out_stream << std::endl;
}

std::istream& operator>>(std::istream& in, CinemaTicket* ticket) {
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
	ticket->zone = static_cast<CinemaZones>(zone);

	return in;
}