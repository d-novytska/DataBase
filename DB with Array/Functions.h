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

struct Initial {
	std::string surname,
		patronymic,
		name;
};

struct Date {
	int day,
		month,
		year;
};

struct Address {
	std::string city;
	int home{};
};

struct Data { 
	Initial _initial;
	Date _date;
	Address _adress;
};

void DataEntry(Data* (&d), int &n);
void ReadingData(Data* (&d), int &n, std::string fileName);
void Print(Data* d, int n);
void DataChange(Data* (&d), int n);
void DeleteData(Data* (&d), int &n);
void Copy(Data* (&d_new), Data* (&d_old), int n); //copy of the data of the all array
void Copy(Data& d_new, Data& d_old); //copy of one array element
void AddData(Data* (&d), int& n);
void DataSorting(Data *d, int n);
void SavingData(Data* d, int n, std::string fileName);
void DataEmpty();