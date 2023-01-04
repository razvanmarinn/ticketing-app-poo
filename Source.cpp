#include <iostream>
#include "Ticket.h"
#include "Date.h"
#include "Seats.h"
#include "Event.h"
#include "User.h"


int main(int argc, char* argv[]) {
	

	User Razvan(30000);

	
	if (argc > 1) {
		std::string filename = argv[1];
		std::cout << "Processing file: " << filename << std::endl;
		// Process the file here
	}
	else {
		std::cout << "No file specified, using menu mode." << std::endl;
		// Use menu mode here
		while (true) {
			std::cout << "Menu:" << std::endl;
			std::cout << "1. Buy tickets" << std::endl;
			std::cout << "2. List tickets" << std::endl;
			std::cout << "3. Quit" << std::endl;
			std::cout << "Enter your choice: ";

			int choice;
			std::cin >> choice;

			switch (choice) {
			case 1: {
				std::cout << "1. Buy fotball ticket" << std::endl;
				std::cout << "2. Buy cinema ticket" << std::endl;
				std::cout << "3.Buy theater ticket" << std::endl;
				std::cout << "4. Quit" << std::endl;
				int choice2;
				std::cin >> choice2;
				switch (choice2) {
				case 1: {

					FotballTicket* Ticket = new FotballTicket();
					std::cin >> Ticket;

					Razvan.buyTicket(Ticket);

				};break;
				case 2: {

					CinemaTicket* Ticket = new CinemaTicket();
					std::cin >> Ticket;

					Razvan.buyTicket(Ticket);
				};break;
				case 3: {

					TheaterTicket* Ticket = new TheaterTicket();
					std::cin >> Ticket;

					Razvan.buyTicket(Ticket);
				};break;
				}
			/*	Ticket ticket();
				std::cin >> ticket;

				
				Razvan.buyTicket(ticket);*/
				break;
			}
			case 2:
				Razvan.print();
				break;
			case 3:
				return 0;
			default:
				std::cout << "Invalid choice." << std::endl;
				break;
			}
		}
		return 0;
	}


	//Date ddate(2002, 12, 20);
	//Date ddate2(2002, 12, 21);
	////std::cout << std::endl << ddate.dateToString();

	//Seats seat(30, Avalaible::FREE);
	//Seats seat2(10, Avalaible::ocuppied);

	//int nr_of_seats = 2;
	//Seats* setx = new Seats[nr_of_seats];
	//setx[0] = seat;
	//setx[1] = seat2;


	//location location(1, 2, setx);

	//Event event(ddate, "Razvn", 30, location, 12);
	//Event event2(ddate2, "Marius", 70, location, 20);
	//Event event3(ddate2, "Meci_fotbal", 90, location, 90000);

	//FotballTicket* asd = new FotballTicket(event3, FotballZones::Stand1);


	//const auto nr_of_tickets = 3;
	//Ticket* tickets[nr_of_tickets];
	//tickets[0] = new CinemaTicket(event2, CinemaZones::VIP);
	//tickets[1] = new FotballTicket(event2, FotballZones::Stand1);
	//tickets[2] = new TheaterTicket(event3, TheaterZones::Box);

	////location.print();


	//std::cout << std::endl << std::endl;
	//User razvan(5000, nr_of_tickets, tickets);
	//razvan.print();

	//User Omar(30000);

	//Omar.buyTicket(asd);

	//Omar.print();

	//std::cout << std::endl << std::endl;	std::cout << std::endl << std::endl;
	//Omar + razvan;
	//Omar++;
	//Omar.print();

	//Date date;
	//std::cout << "Please input date (YEAR, MONTH, DATE) with , between : ";
	//std::cin >> date;
	//std::cout << date.dateToString();
}