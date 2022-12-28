#include <Date.h>



std::string date::dateToString() {
	std::ostringstream dateString;
	dateString << this->year << "-" << this->month << "-" << this->day;
	return dateString.str();
}

int date::getDay() {
	return this->day;
}
int date::getMonth() {
	return this->month;
}
int date::getYear() {
	return this->year;
}

