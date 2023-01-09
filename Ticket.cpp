#include "Ticket.h"
#include <stdlib.h>



Ticket::Ticket():ticketId(rand()){
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

bool Ticket::getAvalaiblity() {
	return this->avalaible;
}

int Ticket::getPrice() {
	return this->price;
}
std::string Ticket::getNameOfTheEvent() {
	return this->event.getName();
}

void Ticket::setAvalaibility() {
	this->avalaible = false;
}

void Ticket::setPrice(int price) {
	this->price = price;
}

void Ticket::operator=(Ticket& ticket) {
	this->price = ticket.price;
	this->event = ticket.event;
}

void Ticket::operator+(int price) {
	if (price > 0) { this->setPrice(this->price + price); }
	
}

std::ostream& operator<<(std::ostream& out, Ticket& ticket) {
	out << std::endl << "Ticket id " << ticket.getId();
	out << std::endl << "Ticket event " << ticket.getNameOfTheEvent();
	out << std::endl << "Ticket price " << ticket.getPrice();

	return out;
}
