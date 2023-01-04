#pragma once
#include "Ticket.h"

class User {
	Ticket** tickets ;
	int nr_of_tickets;
	int balance;



public:
	User();
	User(int balance);
	User(int balance, int nr_of_tickets, Ticket** ticket);
	User(int balance, Ticket* ticket);

	void setTickets(Ticket* ticket);
	void setBalance(int newBalance);
	int getNrOfTickets();
	void print();
	void buyTicket(Ticket* ticket);


	
	void operator++(int);
	User& operator+(const User& other);
};