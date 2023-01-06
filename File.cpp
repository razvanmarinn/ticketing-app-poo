#include "File.h"


void File::create_file() {
	
	User razvan(30000);
	Date date(1999, 10, 10);
	Seats seat1(1, Avalaible::FREE);
	Seats seat2(2, Avalaible::FREE);
	Seats seat3(3, Avalaible::FREE);
	Seats seat4(4, Avalaible::FREE);

	Seats* seats = new Seats[4];

	seats[0] = seat1;
	seats[1] = seat2;
	seats[2] = seat3;
	seats[3] = seat4;
	location location1(1, 4, seats);

	Event event(date, "Fotball Meci", 90, location1, 4);
	FotballTicket* fotbalticket = new FotballTicket(event, FotballZones::Stand1);
	FotballTicket* fotbalticket2 = new FotballTicket(event, FotballZones::Stand2);


	std::array<Ticket*, 5> tickets{};
	tickets[0] = fotbalticket;
	tickets[1] = fotbalticket2;
	
	this->file << 2 << std::endl;
	for (size_t i = 0; i < 2; ++i) {
		this->file << *tickets[i] << std::endl;
	}


}


File::~File() {
	this->file.close();
}

void File::start_files(std::string filename) {


	std::ifstream file;
	file.open(filename);
	while (!file.eof()) {
		FotballTicket* ticket = new FotballTicket();
		ticket->ReadFromFile(file);
	
	}
	if (!file.is_open()) {
		std::cout << "File not found" << std::endl;
		exit(1);
	}
	
}