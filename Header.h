#pragma once
#include "Ticket.h"

class User {
	Ticket** tickets = nullptr;
	int balance;



public:
	User();
	User(int balance);

	 void setTickets(Ticket ticket);
	 void setBalance(int newBalance);
	 Ticket* getTickets();
	 void buyTicket(Ticket ticket);



	void operator++();
};