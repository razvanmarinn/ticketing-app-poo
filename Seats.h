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
	~Seats();
	 friend std::ostream& operator<< (std::ostream& out, const Avalaible& availability);
};