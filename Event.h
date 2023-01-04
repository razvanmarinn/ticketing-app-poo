#pragma once
#include "Location.h"
#include "Date.h"


class Event {
	Date dateOfEvent;
	char* nameOfEvent = nullptr;
	int durationOfEvent; // in minutes
	location locationOfEvent;
	int avalaible_seat;


public:
	Event();
	Event(Date dated,const char* name, int duration, location location_of_event, int avalaible_seats);
	Event(Event& event);
	~Event();

	char* getName();
	void operator=(Event& event);
	friend std::ostream& operator<<(std::ostream& out, Event& event);
};

