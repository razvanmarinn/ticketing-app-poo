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
	~location();

	int getNumberOfSeats();
	int getId();
	Seats getSeats();
	void getEvents();
	void print();

	void operator=(location& location);
	friend std::ostream& operator<<(std::ostream& out, location& location);
	friend std::istream& operator>>(std::istream& in, location& location);
};
