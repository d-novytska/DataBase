#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

/*
	Data:
	1. Initials
	2. Date
	3. Address
*/

struct Initials {
	std::string surname {},
		name {},
		patrinymic {};
};

struct Date {
	int day {},
		month {},
		year {};
};

struct Address {
	std::string city{};
	int home{};
};

class Data {
public:
	Data();
	Data(Initials initials_, Date date_, Address address_);
	~Data();

	void Print();
	void DataEntry(Initials initials_, Date date_, Address address_);
	Initials GetInitials() { return initials; }
	Date GetDate() { return date; }
	Address GetAddress() { return address; }

	Data& operator = (const Data& d_o);

private:
	Initials initials;
	Date date;
	Address address;
};