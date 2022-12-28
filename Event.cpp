#define _CRT_SECURE_NO_WARNINGS

#include <Event.h>



Event::Event(date dated, char* name, int duration, Location location):dateOfEvent(dated), duration(duration), locationOfEvent(location) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Event::Event(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->duration = event.duration;
	this->name = new char[strlen(event.name) + 1];
	strcpy(this->name, event.name);
	this->locationOfEvent = event.locationOfEvent;
}

void Event::operator=(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->duration = event.duration;
	this->name = new char[strlen(event.name) + 1];
	strcpy(this->name, event.name);
	this->locationOfEvent = event.locationOfEvent;
}