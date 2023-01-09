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
	void setAvalaibilityFalse();
	void setAvalaibilityTrue();
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


class FotballTicket : public Ticket {
	FotballZones zone = FotballZones::Stand1;
public:
	FotballTicket();
	FotballTicket(FotballTicket& ticket);
	FotballTicket(Event event, FotballZones zone);
	FotballZones getZone();
	static FotballTicket* read(std::istream& in_stream) ;
	void print() override;
	void write(std::ostream& out_stream)  override;
	bool checkTicket(int id) override;
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
	bool checkTicket(int id) override;
	void write(std::ostream& out_stream)  override;
	friend std::istream& operator>>(std::istream& in, CinemaTicket* ticket);
};

class TheaterTicket : public Ticket {
	TheaterZones zone = TheaterZones::Category1;
public:
	TheaterTicket();
	TheaterTicket(Event event, TheaterZones zone);
	TheaterZones getZone();
	void print() override;
	bool checkTicket(int id) override;
	void write(std::ostream& out_stream)  override;
	friend std::istream& operator>>(std::istream& in, TheaterTicket* ticket);
};