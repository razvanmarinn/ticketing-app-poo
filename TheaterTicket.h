#pragma once
#include "Ticket.h"

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