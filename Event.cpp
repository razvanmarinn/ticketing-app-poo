#define _CRT_SECURE_NO_WARNINGS

#include "Event.h"

Event::Event() {

}
Event::~Event() {
	delete[] this->nameOfEvent;
}

std::ostream& operator<<(std::ostream& out, Event& event) {
	out << event.dateOfEvent.dateToString();
	out <<  event.getName();
	out << event.durationOfEvent;
	out << event.locationOfEvent.getId();
	out << event.avalaible_seat;
	return out;
}

Event::Event(Date dated, const char* name, int duration, location location_of_event, int avalaible_seats):dateOfEvent(dated), durationOfEvent(duration), locationOfEvent(location_of_event), avalaible_seat(avalaible_seats) {
	this->nameOfEvent = new char[strlen(name) + 1];
	strcpy(this->nameOfEvent, name);
}

Event::Event(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->durationOfEvent = event.durationOfEvent;
	this->nameOfEvent = new char[strlen(event.nameOfEvent) + 1];
	strcpy(this->nameOfEvent, event.nameOfEvent);
	this->locationOfEvent = event.locationOfEvent;
	this->avalaible_seat = event.avalaible_seat;
}

void Event::operator=(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->durationOfEvent = event.durationOfEvent;
	this->nameOfEvent = new char[strlen(event.nameOfEvent) + 1];
	strcpy(this->nameOfEvent, event.nameOfEvent);
	this->locationOfEvent = event.locationOfEvent;
	this->avalaible_seat = event.avalaible_seat;
}

char* Event::getName() {
	char* copy = new char[strlen(this->nameOfEvent) + 1];
	strcpy(copy, this->nameOfEvent);
	return copy;
}