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


FotballTicket* FotballTicket::ReadFromFile(std::ifstream& in_file) {

	Date date(1999, 10, 10);
	Seats seat1(1, Avalaible::FREE);
	Seats seat2(2, Avalaible::FREE);

	Seats* seats = new Seats[2];

	seats[0] = seat1;
	seats[1] = seat2;
	
	location location1(1, 4, seats);

	Event event(date, "Fotball Meci", 90, location1, 2);

	int choice;
	in_file >> choice;
	if (choice == 0) {
		std::cout << std::endl <<"Created ticket fotball for stand1 " << std::endl;
		FotballTicket* ticket = new FotballTicket(event, FotballZones::Stand1);
		ticket->print();
		return ticket;
	}
	else {
		std::cout << std::endl << "Created ticket fotball for stand2 " << std::endl;
		FotballTicket* ticket = new FotballTicket(event, FotballZones::Stand2);
		ticket->print();
		return ticket;
	}
	
	
	
	
}
void CinemaTicket::ReadFromFile(std::ifstream& in_file) {
	in_file >> price;
	int choice;
	in_file >> choice;
	if (choice == 0){
		this->zone = CinemaZones::VIP; 
	}
	else {
		this->zone = CinemaZones::Normal; 
	}

}

void TheaterTicket::ReadFromFile(std::ifstream& in_file) {
	in_file >> price;
	int choice;
	in_file >> choice;
	switch (choice) {
	case 1:
		this->zone = TheaterZones::Category1;
		break;
	case 2:
		this->zone = TheaterZones::Category2;
		break;
	case 3:
		this->zone = TheaterZones::Box;
		break;
	}

}




bool Ticket::getAvalaiblity() {
	return this->avalaible;
}


void Ticket::setAvalaibility() {
	this->avalaible = false;

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