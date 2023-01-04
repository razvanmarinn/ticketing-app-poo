#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date() {

}

std::istream& operator>>(std::istream& in, Date& date) {
	char buffer[128];
	in.getline(buffer, sizeof(buffer));

	char* occurence = strtok(buffer, ",");
	date.year = atoi(occurence);

	occurence = strtok(nullptr, ",");
	date.month = atoi(occurence);

	occurence = strtok(nullptr, ",");
	date.day = atoi(occurence);
	return in;
}
std::ostream& operator<<(std::ostream& out, Date& date) {
	out << date.dateToString();
	return out;
}


std::string Date::dateToString() {
	std::ostringstream dateString;
	dateString << this->year << "-" << this->month << "-" << this->day;
	return dateString.str();
}

int Date::getDay() {
	return this->day;
}
int Date::getMonth() {
	return this->month;
}
int Date::getYear() {
	return this->year;
}

void Date::setDay(int day) {
	if(day > 31 || day <0) {
		throw std::exception();
	}
	this->day = day;

	
}

void Date::setMonth(int month) {
	if (month > 12 || month < 0) {
		throw std::exception();
	}
	this->month = month;
}

void Date::setYear(int year) {
	if (year > 2050 || year < 1950) {
		throw std::exception();
	}
	this->year = year;
}


void Date::operator=(Date& date) {
	this->day = date.day;
	this->year = date.year;
	this->month = date.month;
}