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
	out << event.nr_of_tickets;
	return out;
}

Event::Event(Date dated, const char* name, int duration, location location_of_event, int nr_of_tickets):dateOfEvent(dated), durationOfEvent(duration), locationOfEvent(location_of_event), nr_of_tickets(nr_of_tickets) {
	this->nameOfEvent = new char[strlen(name) + 1];
	strcpy(this->nameOfEvent, name);
}

Event::Event(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->durationOfEvent = event.durationOfEvent;
	this->nameOfEvent = new char[strlen(event.nameOfEvent) + 1];
	strcpy(this->nameOfEvent, event.nameOfEvent);
	this->locationOfEvent = event.locationOfEvent;
	this->nr_of_tickets = event.nr_of_tickets;
}

void Event::operator=(Event& event) {
	this->dateOfEvent = event.dateOfEvent;
	this->durationOfEvent = event.durationOfEvent;
	this->nameOfEvent = new char[strlen(event.nameOfEvent) + 1];
	strcpy(this->nameOfEvent, event.nameOfEvent);
	this->locationOfEvent = event.locationOfEvent;
	this->nr_of_tickets = event.nr_of_tickets;
}

char* Event::getName() {
	char* copy = new char[strlen(this->nameOfEvent) + 1];
	strcpy(copy, this->nameOfEvent);
	return copy;
}

void Event::setName(char* name) {
	this->nameOfEvent = new char[strlen(name) + 1];
	strcpy(nameOfEvent, name);
}

std::istream& operator>>(std::istream& in, Event& event) {
	std::cout << "Input date for the event " << std::endl;
	in >> event.dateOfEvent;
	std::cout << "Location of the event: " << std::endl;
	in >> event.locationOfEvent;
	std::cout << "Duration of the event " << std::endl;
	in >> event.durationOfEvent;
	std::cout << "Name of the event " << std::endl;
	char* name = nullptr;
	in >> name;
	event.setName(name);
	std::cout << "Nr of tickets avalaible " << std::endl;
	in >> event.nr_of_tickets;
	return in;
}