#include "Date.h"

Date::Date() {

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