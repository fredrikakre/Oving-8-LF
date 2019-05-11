//Person.h
#pragma once
#include "Car.h"
#include "std_lib_facilities.h"

class Person {
public:
	Person(string name, string email, Car* car = nullptr);
	Person(const Person&) = delete;  
	Person& operator=(const Person&) = delete;
	string getEmail() const;
	string getName() const;
	void setEmail(string email);
	bool hasAvailableSeats() const;
	friend ostream& operator<<(ostream& os, const Person& person);
private:
	string name;
	string email;
	Car* car;
};