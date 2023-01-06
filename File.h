#pragma once
#include <fstream>
#include <cstdlib>
#include "Ticket.h"
#include "Ticket.h"
#include "Date.h"
#include "Seats.h"
#include "Event.h"
#include "User.h"
#include <array>


class File {
	std::fstream file;
	std::string name;
	Ticket** tickets = nullptr;
	int number_of_tickets = 0;



	
public:
	~File();
	void start_files(std::string filename);
	void create_file();
	int getNumberOfTickets();

};