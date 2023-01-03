#pragma once
#include "Seats.h"


class location {
	
	int id;
	int numberOfSeats;
	Seats* seats;
	static int MAX_NR_OF_SEATS_PER_ROW;

public:
	location();
	location(int id,int numberOfSeats, Seats* seats);
	location(location& location);


	int getNumberOfSeats();
	int getId();
	Seats getSeats();
	void getEvents();
	void print();

	void operator=(location& location);
};
