#include "Menu.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>




TicketingMenu::TicketingMenu() {

	std::array<Ticket*, 5> tickets{};
	this->nr_of_avalaible_tickets = 0;
	
}

int TicketingMenu::main_menu() {


	while (true) {

		std::cout << std::endl << "1. Buy tickets" << std::endl;
		std::cout << "2. List tickets" << std::endl;
		std::cout << "3. Add ticket" << std::endl;
		std::cout << "4. Quit" << std::endl;
		std::cout << "Enter your choice: ";

		int choice;
		std::cin >> choice;
		system("cls");
		switch (choice) {
		case 1:
			while (true) {
				for (auto i = 0; i < this->nr_of_avalaible_tickets; i++) {
					if (avalaibletickets[i]->getAvalaiblity() == 1){ avalaibletickets[i]->print(); }
					
				}
				std::cout << std::endl << "Which ticket do you want?" << std::endl;
				for (auto i = 0; i < this->nr_of_avalaible_tickets; i++) {
					if (avalaibletickets[i]->getAvalaiblity() == 1) { std::cout << std::endl << i + 1 << ". Ticket " << i + 1; }
				}
				if (this->nr_of_avalaible_tickets == 0) {
					std::cout << std::endl << "There are no tickets avalaible" << std::endl;
					break;
				}
				
				std::cout << std::endl << "9. Back to main menu" << std::endl;

				int choice2;
				std::cin >> choice2;

				switch (choice2) {
				case 1: {
					this->actualuser->buyTicket(this->avalaibletickets[0]);
					this->nr_of_avalaible_tickets--;
					break;
				}
				case 2: {
					this->actualuser->buyTicket(this->avalaibletickets[1]);
					this->nr_of_avalaible_tickets--;
					break;
				}
				case 3: {
					this->actualuser->buyTicket(this->avalaibletickets[2]);
					this->nr_of_avalaible_tickets--;
					break;

				case 4: {
					this->actualuser->buyTicket(this->avalaibletickets[3]);
					this->nr_of_avalaible_tickets--;
					break;
				} 
				case 5: {
					this->actualuser->buyTicket(this->avalaibletickets[4]);
					this->nr_of_avalaible_tickets--;
					break;
				}
				case 6: {
					return 0;// Exit the second menu.
					break;
				}
				default:
					std::cout << "Invalid choice." << std::endl;
					break;
				}

				}
				break;

		case 2:
			this->actualuser->print();
			break;
		case 3:
			std::cout << "Add ticket" << std::endl;
			this->create_ticket();
			break;
		case 4:
			return 0;
		default:
			std::cout << "Invalid choice." << std::endl;
			break;
			}
		};
	}
	
};



void TicketingMenu::create_ticket() {
	std::cout << "Create ticket" << std::endl;
	std::cout << "1. Fotball Ticket" << std::endl;
	std::cout << "2. Cinema Ticket" << std::endl;
	std::cout << "3. Theater Ticket" << std::endl;
	std::cout << "4. Quit" << std::endl;
	
	int choice;
	std::cin >> choice;
	system("cls");
	switch (choice) {
	case 1: {
		FotballTicket* ticket = this->create_fotball_ticket();
		this->avalaibletickets[this->nr_of_avalaible_tickets] = ticket;
		this->nr_of_avalaible_tickets++;

	}; break;
	case 2: {

		CinemaTicket* ticket = this->create_cinema_ticket();
		this->avalaibletickets[this->nr_of_avalaible_tickets] = ticket;
		this->nr_of_avalaible_tickets++;

	}; break;
	case 3: {
		TheaterTicket* ticket = this->create_theater_ticket();
		this->avalaibletickets[this->nr_of_avalaible_tickets] = ticket;
		this->nr_of_avalaible_tickets++;

	}; break;

	case 4: {
		return;
	}; break;


	};


};



FotballTicket* TicketingMenu::create_fotball_ticket() {
	{
		std::cout << "Create fotball ticket" << std::endl;
		std::cout << "Enter the date: " << std::endl;
		int year, month, day;
		std::cin >> year >> month >> day;
		Date date(year, month, day);
		std::cout << "Enter the event name: " << std::endl;
		std::string name;
		std::cin >> name;
		const char* name_char = name.c_str();
		std::cout << "Enter the duration: " << std::endl;
		int duration;
		std::cin >> duration;
		std::cout << "Enter the number of seats: " << std::endl;
		int number_of_seats;
		std::cin >> number_of_seats;
		Seats* seats = new Seats[number_of_seats];
		for (int i = 0; i < number_of_seats; i++) {
			std::cout << "Enter the seat number: " << std::endl;
			int seat_number;
			std::cin >> seat_number;
			std::cout << "Enter the seat status: " << std::endl;
			int seat_status;
			std::cin >> seat_status;
			Seats seat(seat_number, (Avalaible)seat_status);
			seats[i] = seat;
		}
		std::cout << "Enter the zone: " << std::endl;
		int zone;
		std::cin >> zone;
		location loc(number_of_seats, number_of_seats, seats);
		Event event(date, name_char, duration, loc, number_of_seats);
		FotballTicket* fotbalticket = new FotballTicket(event, (FotballZones)zone);
		fotbalticket->print();
		return fotbalticket;
	}
}



CinemaTicket* TicketingMenu::create_cinema_ticket() {
	std::cout << "Create cinema ticket" << std::endl;
	std::cout << "Enter the date: " << std::endl;
	int year, month, day;
	std::cin >> year >> month >> day;
	Date date(year, month, day);
	std::cout << "Enter the event name: " << std::endl;
	std::string name;
	std::cin >> name;
	const char* name_char = name.c_str();
	std::cout << "Enter the duration: " << std::endl;
	int duration;
	std::cin >> duration;
	std::cout << "Enter the number of seats: " << std::endl;
	int number_of_seats;
	std::cin >> number_of_seats;
	Seats* seats = new Seats[number_of_seats];
	for (int i = 0; i < number_of_seats; i++) {
		std::cout << "Enter the seat number: " << std::endl;
		int seat_number;
		std::cin >> seat_number;
		std::cout << "Enter the seat status: " << std::endl;
		int seat_status;
		std::cin >> seat_status;
		Seats seat(seat_number, (Avalaible)seat_status);
		seats[i] = seat;
	}
	std::cout << "Enter the zone: " << std::endl;
	int zone;
	std::cin >> zone;
	location loc(number_of_seats, number_of_seats, seats);
	Event event(date, name_char, duration, loc, number_of_seats);
	CinemaTicket* cinematicket = new CinemaTicket(event, (CinemaZones)zone);
	cinematicket->print();
	return cinematicket;
}

TheaterTicket* TicketingMenu::create_theater_ticket() {
	std::cout << "Create theater ticket" << std::endl;
	std::cout << "Enter the date: " << std::endl;
	int year, month, day;
	std::cin >> year >> month >> day;
	Date date(year, month, day);
	std::cout << "Enter the event name: " << std::endl;
	std::string name;
	std::cin >> name;
	const char* name_char = name.c_str();
	std::cout << "Enter the duration: " << std::endl;
	int duration;
	std::cin >> duration;
	std::cout << "Enter the number of seats: " << std::endl;
	int number_of_seats;
	std::cin >> number_of_seats;
	Seats* seats = new Seats[number_of_seats];
	for (int i = 0; i < number_of_seats; i++) {
		std::cout << "Enter the seat number: " << std::endl;
		int seat_number;
		std::cin >> seat_number;
		std::cout << "Enter the seat status: " << std::endl;
		int seat_status;
		std::cin >> seat_status;
		Seats seat(seat_number, (Avalaible)seat_status);
		seats[i] = seat;
	}
	std::cout << "Enter the zone: " << std::endl;
	int zone;
	std::cin >> zone;
	location loc(number_of_seats, number_of_seats, seats);
	Event event(date, name_char, duration, loc, number_of_seats);
	TheaterTicket* theaterticket = new TheaterTicket(event, (TheaterZones)zone);
	theaterticket->print();
	return theaterticket;
}



void TicketingMenu::create_user() {
	std::cout << "Enter the balance: " << std::endl;
	int balance;
	std::cin >> balance;


	User* user = new User(balance);
	this->actualuser = user;

	std::cout << "Entering main menu...";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	main_menu();
	std::cout << std::endl;

	
}
