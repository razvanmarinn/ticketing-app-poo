#pragma once
#include "Ticket.h"


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