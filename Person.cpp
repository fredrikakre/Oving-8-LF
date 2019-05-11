// Person.cpp
#include "Person.h"
#include "std_lib_facilities.h"

Person::Person(string name, string email, Car* car)
	: name{ name }, email{ email }, car{ car }
{}
string Person::getEmail() const { return email; }
string Person::getName() const { return name; }
void Person::setEmail(string mailAdr) { email = mailAdr; }
bool Person::hasAvailableSeats() const {
    if (car != nullptr ) {
        return car->hasFreeSeats();
    }
    return false;
}
ostream& operator<<(ostream& os, const Person& p) {
	return os << p.name << " (" << p.email << ")";
}