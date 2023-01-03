#include "Ticket.h"
#include <stdlib.h>


Ticket::Ticket():ticketId(rand()){
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
	if (price < 0 || price < 20000) {
		throw std::exception();
	}
	this->price = price;
}


void Ticket::operator=(Ticket& ticket) {
	this->price = ticket.price;
	this->event = ticket.event;
}