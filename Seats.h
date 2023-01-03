#pragma once
#include <iostream>
#include <string>
#include <sstream>


enum Avalaible {
	FREE,
	ocuppied
};

class Seats {

	const int seatId;
	Avalaible avalaibility;
public:

	Seats();
	Seats(Seats& seat);
	Seats(int id, Avalaible availability);
	~Seats();
	
	int getId();
	Avalaible getAvalaibility();
	void setAvalaibility(Avalaible avalaibility);

	void operator=(Seats& seat);
	friend std::ostream& operator<<(std::ostream& out, Seats& seat);
};