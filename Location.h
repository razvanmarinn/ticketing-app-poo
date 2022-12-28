#pragma once
#include <Event.h>
#include <Seats.h>



class Location {
	static int MAX_NR_OF_SEATS;
	const int numberOfRows;
	Seats** seats = nullptr;
	Event** events = nullptr;

public:
	Location();


	inline int getNumberOfRows();
	Seats* getSeats();
	Event* getEvents();


	void operator=(Location& location);
};

//
//class FotballStadium : public Location {
//	
//};
//class Theater : public Location {
//
//};
//
//class Cinema : public Location {
//
//};
