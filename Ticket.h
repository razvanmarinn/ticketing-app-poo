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
	
protected:
	Event event;
	bool avalaible;
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
	bool checkTicket(int id);
	virtual void print() = 0;

	friend class FotballTicket;
	friend class CinemaTicket;
	//friend class TheaterTicket;


	void operator=(Ticket& ticket);
	void operator+(int price);

	friend std::ostream& operator<<(std::ostream& out, Ticket& ticket);
};


class FotballTicket : public Ticket {
	FotballZones zone = FotballZones::Stand1;
public:
	FotballTicket();
	FotballTicket(Event event, FotballZones zone);
	FotballZones getZone();
	void print() override;
	friend std::istream& operator>>(std::istream& in, FotballTicket* ticket);
};




class CinemaTicket : public Ticket {
	CinemaZones zone = CinemaZones::Normal;
public:
	CinemaTicket();
	CinemaTicket(CinemaTicket& other);
	CinemaTicket(Event event, CinemaZones zone);
	CinemaZones getZone();
	void print() override;
	friend std::istream& operator>>(std::istream& in, CinemaTicket* ticket);
};

class TheaterTicket : public Ticket {
	TheaterZones zone;
public:
	TheaterTicket();
	TheaterTicket(Event event, TheaterZones zone);
	TheaterZones getZone();
	void print() override;
	friend std::istream& operator>>(std::istream& in, TheaterTicket* ticket);
};