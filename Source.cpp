#include <iostream>
#include "Ticket.h"
#include "Date.h"
#include "Seats.h"
#include "Event.h"
#include "User.h"


int main() {

	//FotballTicket fotballticket2;
	//CinemaTicket cinematicket;
	//std::cout << fotballticket.getId() << std::endl;


	Date ddate(2002, 12, 20);
	Date ddate2(2002, 12, 21);
	std::cout << std::endl << ddate.dateToString();

	Seats seat(30, Avalaible::FREE);
	Seats seat2(10, Avalaible::ocuppied);
	int nr_of_seats = 2;
	Seats* setx = new Seats[nr_of_seats];
	setx[0] = seat;
	setx[1] = seat2;


	location location(1, 2, setx);

	Event event(ddate, "TEST", 30, location, 12);
	Event event2(ddate2, "TEST2", 70, location, 20);
	Event event3(ddate2, "Meci_fotbal", 90, location, 90000);

	FotballTicket fotballticket(event3, FotballZones::Stand1);
	CinemaTicket cinematicket(event2, CinemaZones::VIP);
	Ticket ticket(1000, event);
	Ticket ticket5(3000, event);
	Ticket ticket2(900, event2);
	auto nr_of_tickets = 3;
	Ticket* tickets = new Ticket[nr_of_tickets];
	tickets[0] = ticket;
	tickets[1] = ticket2;
	tickets[2] = ticket5;

	location.print();

	std::cout << std::endl << std::endl;
	User razvan(5000, nr_of_tickets, tickets);

	razvan.print();


	User Omar(30000);
	Omar.print();
	Omar.buyTicket(cinematicket);
	Omar.print();
	

}