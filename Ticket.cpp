#include "Ticket.h"
#include <stdlib.h>

FotballTicket::FotballTicket(){
}
CinemaTicket::CinemaTicket() {
}
TheaterTicket::TheaterTicket() {
}
Ticket::Ticket():ticketId(rand()){
}
CinemaTicket::CinemaTicket(CinemaTicket& other) :Ticket(other.getPrice(), other.event), zone(other.zone) {
}

bool Ticket::getAvalaiblity() {
	return this->avalaible;
}


void Ticket::setAvalaibility() {
	this->avalaible = true;

}

std::istream& operator>>(std::istream& in, FotballTicket* ticket) {
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
	ticket->zone = static_cast<FotballZones>(zone);

	return in;
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
std::ostream& operator<<(std::ostream& out, Ticket& ticket) {
	out << std::endl << "Ticket id " << ticket.getId();
	out << std::endl << "Ticket event " << ticket.getNameOfTheEvent();
	out << std::endl << "Ticket price " << ticket.getPrice();

	return out;
}



Ticket::Ticket(Event event) : ticketId(rand()) {
	this->event = event;
	this->setPrice(0);

}

Ticket::Ticket(int price, Event event):ticketId(rand()) , price(price), event(event){

}
bool Ticket::checkTicket(int id){
	if (id != this->ticketId ){
		return false;
	}
	return true;
};

int Ticket::getId() {
	return this->ticketId;
}


int Ticket::getPrice() {
	return this->price;
}
std::string Ticket::getNameOfTheEvent() {
	return this->event.getName();
}

void Ticket::setPrice(int price) {
	/*if (price < 0 || price < 20000) {
		throw std::exception();
	}*/
	this->price = price;
}


void Ticket::operator=(Ticket& ticket) {
	this->price = ticket.price;
	this->event = ticket.event;
}

void Ticket::operator+(int price) {
	if (price > 0) { this->setPrice(this->price + price); }
	
}


FotballTicket::FotballTicket(Event event, FotballZones zone) : Ticket(0 , event) {
	this->zone = zone;
	if (zone == 0) {
		this->setPrice(350);
	}
	this->setPrice(500);

}


FotballZones FotballTicket::getZone() {
	return this->zone;
}
CinemaZones CinemaTicket::getZone() {
	return this->zone;
}
TheaterZones TheaterTicket::getZone() {
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
		std::cout <<"Stand2";
	}
	std::cout << std::endl << "======================";
}
//

CinemaTicket::CinemaTicket(Event event, CinemaZones zone): Ticket(0, event) {
	this->zone = zone;
	if (zone == 1) {
		this->setPrice(3500);
	}
	this->setPrice(5000);


};

void CinemaTicket::print(){
	std::cout << std::endl << "Ticket id " << this->getId();
	std::cout << std::endl << "Ticket event " << this->getNameOfTheEvent();
	std::cout << std::endl << "Ticket price " << this->getPrice();
	std::cout << std::endl << "Ticket zone ";
	if (this->getZone() == 0) {
		std::cout << "VIP";
	}
	else {
		std::cout  << "Normal";
	}
	std::cout << std::endl << "======================";
}
//void Ticket::print() {
//	std::cout << "ASD";
//}


TheaterTicket::TheaterTicket(Event event, TheaterZones zone): Ticket(0, event) {
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