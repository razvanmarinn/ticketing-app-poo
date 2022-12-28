#pragma once
#include <Ticket.h>

class User {
	Ticket** tickets = nullptr;
	int balance;



public:
	User();

	inline void setTickets(Ticket ticket);
	inline void setBalance(int newBalance);
	inline Ticket* getTickets();
	inline void buyTicket(Ticket ticket);



	void operator++();
};