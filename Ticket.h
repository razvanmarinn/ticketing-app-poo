#pragma once
#include "Event.h"


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
	Event event;

public:
	Ticket(); 
	Ticket(Event event);
	Ticket(int price, Event event);
	int getId();
	int getPrice();
	std::string getNameOfTheEvent();
	void setPrice(int price);
	bool checkTicket(int id);
	virtual void print() = 0;

	friend class FotballTicket;
	friend class CinemaTicket;
	//friend class TheaterTicket;


	void operator=(Ticket& ticket);
	void operator+(int price);
};


class FotballTicket : public Ticket {
	FotballZones zone = FotballZones::Stand1;
public:

	FotballTicket(Event event, FotballZones zone);
	FotballZones getZone();
	void print() override;
};




class CinemaTicket : public Ticket {
	CinemaZones zone = CinemaZones::Normal;
public:
	CinemaTicket(Event event, CinemaZones zone);
	CinemaZones getZone();
	void print() override;
};

class TheaterTicket : public Ticket {
	TheaterZones zone;
public:
	TheaterTicket(Event event, TheaterZones zone);
	TheaterZones getZone();
	void print() override;
};