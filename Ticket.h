#pragma once
#include "Event.h"
#include <fstream>

enum FotballZones {
	Stand1,
	Stand2
};
enum TheaterZones {
	Category1,
	Category2,
	Box
};
enum CinemaZones {
	VIP,
	Normal
};


class Ticket {
	const int ticketId;
	int price = 0;
	
protected:
	Event event;
	bool avalaible = true;
public:
	Ticket(); 
	Ticket(Event event);
	Ticket(int price, Event event);
	int getId();
	int getPrice();
	bool getAvalaiblity();
	void setAvalaibility();
	std::string getNameOfTheEvent();
	void setPrice(int price);
	virtual bool checkTicket(int id);
	virtual void write(std::ostream& out_stream)  = 0;
	virtual void print() = 0;
	friend class FotballTicket;
	friend class CinemaTicket;
	friend class TheaterTicket;


	void operator=(Ticket& ticket);
	void operator+(int price);

	friend std::ostream& operator<<(std::ostream& out, Ticket& ticket);
};
