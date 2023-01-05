#pragma once
#include <stdlib.h>
#include "Ticket.h"
#include "Date.h"
#include "Seats.h"
#include "Event.h"
#include "User.h"
#include <array>



class TicketingMenu {
	User* actualuser;
	Ticket* avalaibletickets[5];
	int nr_of_avalaible_tickets;
public:


	TicketingMenu();
	int main_menu();
	void create_ticket();
	FotballTicket* create_fotball_ticket();
	CinemaTicket* create_cinema_ticket();
	TheaterTicket* create_theater_ticket();
	void create_user();




	
};