#pragma once
#include "Location.h"
#include "Date.h"


class Event {
	Date dateOfEvent;
	char* nameOfEvent = nullptr;
	int durationOfEvent; // in minutes
	location locationOfEvent;


public:
	Event();
	Event(Date dated, char* name, int duration, location location_of_event);
	Event(Event& event);
	~Event();


	 void operator=(Event& event);
};

