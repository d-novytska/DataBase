#include "Data.h"

Data::Data() {

	initials.surname = "";
	initials.name = "";
	initials.patrinymic = "";

	date.day = 0;
	date.month = 0;
	date.year = 0;

	address.city = "";
	address.home = 0;
}

Data::Data(Initials initials_, Date date_, Address address_) {

	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.city = address_.city;
	address.home = address_.home;
}

Data::~Data() {
}

void Data::Print() {
	std::cout << "FIO: " << initials.surname << " " << initials.name << " " << initials.patrinymic << std::endl;
	std::cout << "Date: " << date.day << " " << date.month << " " << date.year << std::endl;
	std::cout << "Address: " << address.city << " " << address.home << std::endl;
}

void Data::DataEntry(Initials initials_, Date date_, Address address_) {

	initials.surname = initials_.surname;
	initials.name = initials_.name;
	initials.patrinymic = initials_.patrinymic;

	date.day = date_.day;
	date.month = date_.month;
	date.year = date_.year;

	address.city = address_.city;
	address.home = address_.home;
}

Data& Data::operator=(const Data& d_o) { 

	initials.surname = d_o.initials.surname;
	initials.name = d_o.initials.name;
	initials.patrinymic = d_o.initials.patrinymic;

	date.day = d_o.date.day;
	date.month = d_o.date.month;
	date.year = d_o.date.year;

	address.city = d_o.address.city;
	address.home = d_o.address.home;

	return *this;
}
