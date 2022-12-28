#pragma once
#include <iostream>
#include <string>
#include <sstream>


class date {
	int year;
	int day;
	int month;


public:
	date(int year, int month, int day) : year(year), month(month), day(day) {

	}

	date();
	~date() {}

	
	inline int getYear();
	inline int getDay();
	inline int getMonth();
	inline void setYear();
	inline void setDay();
	inline void setMonth();

	inline std::string dateToString();

};