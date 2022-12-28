#pragma once
#include <string>
#include <Location.h>
#include <Date.h>


class Event {
	date dateOfEvent;
	char* name = nullptr;
	int duration; // in minutes
	Location locationOfEvent;


public:
	Event();
	Event(date dated, char* name, int duration, Location location);
	Event(Event& event);



	void operator=(Event& event);
};