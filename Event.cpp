#define _CRT_SECURE_NO_WARNINGS

#include "Event.h"

Event::Event() {

}
Event::~Event() {
	delete[] this->nameOfEvent;
}

Event::Event(Date dated, const char* name, int duration, location location_of_event):dateOfEvent(dated), durationOfEvent(duration), locationOfEvent(location_of_event) {
	this->nameOfEvent = new char[strlen(name) + 1];
	strcpy(this->nameOfEvent, name);
}

Event::Event(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->durationOfEvent = event.durationOfEvent;
	this->nameOfEvent = new char[strlen(event.nameOfEvent) + 1];
	strcpy(this->nameOfEvent, event.nameOfEvent);
	this->locationOfEvent = event.locationOfEvent;
}

void Event::operator=(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->durationOfEvent = event.durationOfEvent;
	this->nameOfEvent = new char[strlen(event.nameOfEvent) + 1];
	strcpy(this->nameOfEvent, event.nameOfEvent);
	this->locationOfEvent = event.locationOfEvent;
}

char* Event::getName() {
	char* copy = new char[strlen(this->nameOfEvent) + 1];
	strcpy(copy, this->nameOfEvent);
	return copy;
}