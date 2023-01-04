#pragma once
#include "Location.h"
#include "Date.h"


class Event {
	Date dateOfEvent;
	char* nameOfEvent = nullptr;
	int durationOfEvent; // in minutes
	location locationOfEvent;
	int nr_of_tickets;


public:
	Event();
	Event(Date dated,const char* name, int duration, location location_of_event, int nr_of_tickets);
	Event(Event& event);
	~Event();

	char* getName();
	void setName(char* name);
	void operator=(Event& event);
	friend std::ostream& operator<<(std::ostream& out, Event& event);
	friend std::istream& operator>>(std::istream& in, Event& event);
};

