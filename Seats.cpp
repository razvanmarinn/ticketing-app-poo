#include <Seats.h>


std::ostream& operator << (std::ostream& out, const Avalaible& availability) {
	switch (availability) {
	case Avalaible::FREE:
		out << "free"; break;
	case Avalaible::ocuppied:
		out << "ocuppied"; break;
	}
	return out;
}