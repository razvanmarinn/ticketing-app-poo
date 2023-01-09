#pragma once

#include "Ticket.h"


class FotballTicket : public Ticket {
	FotballZones zone = FotballZones::Stand1;
public:
	FotballTicket();
	FotballTicket(FotballTicket& ticket);
	FotballTicket(Event event, FotballZones zone);
	FotballZones getZone();
	static FotballTicket* read(std::istream& in_stream);
	void print() override;
	void write(std::ostream& out_stream)  override;
	bool checkTicket(int id) override;
	friend std::istream& operator>>(std::istream& in, FotballTicket* ticket);
};
