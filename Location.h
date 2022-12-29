#pragma once
#include "Seats.h"


class location {
	static int MAX_NR_OF_SEATS;
	int numberOfRows;
	Seats** seats;

public:
	location();
	location(location& location);


	 int getNumberOfRows();
	 void getSeats();
	 void getEvents();


	 void operator=(location& location);
};
