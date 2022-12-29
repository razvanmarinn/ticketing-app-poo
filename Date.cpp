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

void Date::operator=(Date& date) {
	this->day = date.day;
	this->year = date.year;
	this->month = date.month;
}