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

	Ticket(int price, Event event);
	int getId();
	int getPrice();
	std::string getNameOfTheEvent();
	void setPrice(int price);
	bool checkTicket(int id);


	friend class FotballTicket;
	friend class CinemaTicket;
	friend class TheaterTicket;


	void operator=(Ticket& ticket);
};




//
//class CinemaTicket : public Ticket {
//	CinemaZones zone;
//public:
//	CinemaTicket(Event event, CinemaZones zone) : Ticket() {
//		this->event = event;
//		this->zone = zone;
//		if (zone == 1) {
//			this->setPrice(3500);
//		}
//		this->setPrice(5000);
//
//	}
//};
//
//class TheaterTicket : public Ticket {
//	TheaterZones zone;
//public:
//	TheaterTicket(Event event, TheaterZones zone) : Ticket() {
//		this->event = event;
//		this->zone = zone;
//		if (zone == 1) {
//			this->setPrice(3500);
//		}
//		this->setPrice(5000);
//
//	}
//};