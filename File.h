#pragma once
#include <fstream>
#include <cstdlib>
#include "Ticket.h"
#include "FotballTicket.h"
#include "TheaterTicket.h"
#include "CinemaTicket.h"
#include "Location.h"
#include "Date.h"
#include "Seats.h"
#include "Event.h"
#include "User.h"
#include <array>


class File {
	std::fstream file;
	std::string name;
protected:
	Ticket** tickets = nullptr;
	int number_of_tickets = 0;




	
public:
	File(std::string filename);
	File();
	~File();
	void start_files(std::string filename);
	int getNumberOfTickets();
	Ticket* getTickets(int nr);
	void outputTickets(Ticket** tickets, int nr_of_tickets, std::string filename);
};