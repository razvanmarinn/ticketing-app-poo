#include <iostream>
#include "Ticket.h"
#include "Date.h"
#include "Seats.h"
#include "Event.h"
#include "User.h"


int main(int argc, char* argv[]) {
	//if (argc > 1) {
	//	std::string filename = argv[1];
	//	std::cout << "Processing file: " << filename << std::endl;
	//	// Process the file here
	//}
	//else {
	//	std::cout << "No file specified, using menu mode." << std::endl;
	//	// Use menu mode here
	//}
	//return 0;



	Date ddate(2002, 12, 20);
	Date ddate2(2002, 12, 21);
	//std::cout << std::endl << ddate.dateToString();

	Seats seat(30, Avalaible::FREE);
	Seats seat2(10, Avalaible::ocuppied);

	int nr_of_seats = 2;
	Seats* setx = new Seats[nr_of_seats];
	setx[0] = seat;
	setx[1] = seat2;


	location location(1, 2, setx);

	Event event(ddate, "Razvn", 30, location, 12);
	Event event2(ddate2, "Marius", 70, location, 20);
	Event event3(ddate2, "Meci_fotbal", 90, location, 90000);

	FotballTicket* asd = new FotballTicket(event3, FotballZones::Stand1);


	const auto nr_of_tickets = 3;
	Ticket* tickets[nr_of_tickets];
	tickets[0] = new CinemaTicket(event2, CinemaZones::VIP);
	tickets[1] = new FotballTicket(event2, FotballZones::Stand1);
	tickets[2] = new TheaterTicket(event3, TheaterZones::Box);

	//location.print();


	std::cout << std::endl << std::endl;
	User razvan(5000, nr_of_tickets, tickets);
	razvan.print();

	User Omar(30000);

	Omar.buyTicket(asd);

	Omar.print();

	std::cout << std::endl << std::endl;	std::cout << std::endl << std::endl;
	Omar + razvan;
	Omar++;
	Omar.print();
	

}