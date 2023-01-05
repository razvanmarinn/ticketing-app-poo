#include "User.h"




User& User::operator+(const User& other) {
	this->setBalance(this->balance + other.balance);
	for (auto i = 0; i < other.nr_of_tickets; i++) {
		this->setTickets(other.tickets[i]);
	}

	return *this;
}
void User::operator++(int) {
	this->setBalance(this->balance + 100);
}


void User::setBalance(int balance) {
	if (balance < 0) {
		throw std::exception();
	}
	this->balance = balance;
}

int User::getNrOfTickets() {
	return this->nr_of_tickets;
}
void User::setTickets(Ticket* ticket) {
	Ticket** temp = new Ticket*[this->nr_of_tickets];
	for (auto i = 0; i < nr_of_tickets; i++) {
		temp[i] = this->tickets[i];
	}
	delete[] this->tickets;
	this->tickets = new Ticket*[this->nr_of_tickets + 1];
	for (auto i = 0; i < nr_of_tickets; i++) {
		this->tickets[i] = temp[i];
	}
	this->nr_of_tickets++;
	this->tickets[nr_of_tickets-1] = ticket;
}

User::User(int balance) {
	this->setBalance(balance);
}

User::User(int balance, int nr_of_tickets, Ticket** ticket) {
	this->setBalance(balance);
	this->nr_of_tickets = nr_of_tickets;
	this->tickets = new Ticket*[nr_of_tickets];
	for (auto i = 0; i < nr_of_tickets; i++) {
		this->tickets[i] = ticket[i];
		this->tickets[i]->setAvalaibility();
	}
}



User::User(int balance, Ticket* ticket) {
	this->setBalance(balance);
	this->nr_of_tickets = 1;
	this->tickets = new Ticket*[nr_of_tickets];
	this->tickets[0] = ticket;



}

void User::buyTicket(Ticket* ticket) {
	this->setTickets(ticket);
	this->balance = this->balance - ticket->getPrice();
	ticket->setAvalaibility();
}


void User::print() {
	std::cout << std::endl << "Balance of the user -> " << this->balance;
	std::cout << std::endl << "Number of tickets owned -> " << this->nr_of_tickets;
	for (auto i = 0; i < nr_of_tickets; i++) {
		this->tickets[i]->print();
	}

}