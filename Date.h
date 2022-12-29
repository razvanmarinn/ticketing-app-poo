#pragma once
#include <iostream>
#include <string>
#include <sstream>


class Date {
	int year;
	int day;
	int month;


public:
	Date(int year, int month, int day) : year(year), month(month), day(day) {

	}

	Date();
	~Date() {}

	
	 int getYear();
	 int getDay();
	 int getMonth();
	 void setYear();
	 void setDay();
	 void setMonth();

	 std::string dateToString();


	 void operator=(Date& date);

};