#include "Ticket.h"
#include <stdlib.h>


Ticket::Ticket():ticketId(rand()){
}


bool Ticket::checkTicket(int id){
	if (id != this->ticketId ){
		return false;
	}
	return true;
};

int Ticket::getId() {
	return this->ticketId;
}