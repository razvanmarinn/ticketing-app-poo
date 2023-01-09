#include "File.h"
#include "Menu.h"



File::~File() {
	delete[] this->tickets;
	this->file.close();
}

void File::start_files(std::string filename) {


	std::ifstream file;
	file.open(filename);
	while (!file.eof()) {
		FotballTicket* ticket = FotballTicket::read(file);
		
		this->tickets = new Ticket * [this->number_of_tickets + 1];
		this->tickets[this->number_of_tickets] = ticket;
		this->number_of_tickets++;

	}
	if (!file.is_open()) {
		std::cout << "File not found" << std::endl;
		exit(1);
	}
	
}


Ticket* File::getTickets(int nr) {
	return this->tickets[nr];
}

int File::getNumberOfTickets() {
	return this->number_of_tickets;
}



void File::outputTickets(Ticket** tickets, int nr_of_tickets, std::string filename) {
	std::ofstream file;
	file.open(filename);
	for (auto i = 0; i < nr_of_tickets; i++) {
		tickets[i]->write(file);
	}
	file.close();
}


File::File(std::string filename) {
	this->name = filename;
}

File::File() {
	
}