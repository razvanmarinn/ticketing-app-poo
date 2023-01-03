#include "User.h"




void User::setBalance(int balance) {
	if (balance < 0) {
		throw std::exception();
	}
	this->balance = balance;
}


void User::setTickets(Ticket ticket) {
	Ticket* temp = new Ticket[this->nr_of_tickets];
	for (auto i = 0; i < nr_of_tickets; i++) {
		temp[i] = this->tickets[i];
	}
	delete[] this->tickets;
	this->tickets = new Ticket[this->nr_of_tickets + 1];
	for (auto i = 0; i < nr_of_tickets; i++) {
		this->tickets[i] = temp[i];
	}
	this->nr_of_tickets++;
	this->tickets[nr_of_tickets-1] = ticket;
}

User::User(int balance) {
	this->setBalance(balance);
}

User::User(int balance, int nr_of_tickets, Ticket* ticket) {
	this->setBalance(balance);
	this->nr_of_tickets = nr_of_tickets;
	this->tickets = new Ticket[nr_of_tickets];
	for (auto i = 0; i < nr_of_tickets; i++) {
		this->tickets[i] = ticket[i];
	}
}



User::User(int balance, Ticket ticket) {
	this->setBalance(balance);
	this->nr_of_tickets = 1;
	this->tickets = new Ticket[nr_of_tickets];
	this->tickets[0] = ticket;



}

void User::buyTicket(Ticket ticket) {
	this->setTickets(ticket);
	this->balance = this->balance - ticket.getPrice();
}


void User::print() {
	std::cout << std::endl << "Balance of the user -> " << this->balance;
	std::cout << std::endl << "Number of tickets owned -> " << this->nr_of_tickets;
	for (auto i = 0; i < nr_of_tickets; i++) {
		std::cout << std::endl << "Ticket id " << this->tickets[i].getId();
		std::cout << std::endl << "Ticket event " << this->tickets[i].getNameOfTheEvent();
		std::cout << std::endl << "Ticket price " << this->tickets[i].getPrice();
		std::cout << std::endl << "======================";
	}
}