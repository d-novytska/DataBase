#include "Functions.h"

void DataEntry(Data* (&d), int &n) { 
	std::cout << "Enter couner data: ";
	std::cin >> n;

	d = new Data [n];

	for (int i = 0; i < n; ++i) {
		std::cout << "Enter FIO: ";
		std::cin >> d[i]._initial.surname;
		std::cin >> d[i]._initial.name;
		std::cin >> d[i]._initial.patronymic;

		std::cout << "Enter date: ";
		std::cin >> d[i]._date.day;
		std::cin >> d[i]._date.month;
		std::cin >> d[i]._date.year;

		std::cout << "Enter address: ";
		std::cin >> d[i]._adress.city;
		std::cin >> d[i]._adress.home;

		std::cout << "______________" << std::endl;
	}
}

void ReadingData(Data* (&d), int &n, std::string fileName) { 

	std::ifstream reading(fileName); 

	if (reading) {
		reading >> n;

		d = new Data[n]; 

		for (int i = 0; i < n; ++i) { 
			reading >> d[i]._initial.surname;
			reading >> d[i]._initial.patronymic;
			reading >> d[i]._initial.name;

			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;

			reading >> d[i]._adress.city;
			reading >> d[i]._adress.home;
		}
		std::cout << "Data is reading!" << std::endl;
	}
	else {
		std::cout << "Error is opening file!" << std::endl;
	}
	
	reading.close();
}

void Print(Data* d, int n) { 
	for (int i = 0; i < n; ++i) {
		std::cout << "Data " << i + 1 << ": " << std::endl;

		std::cout << "FIO: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << std::endl;
		std::cout << "Date: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << std::endl;
		std::cout << "Address: " << d[i]._adress.city << " " << d[i]._adress.home << std::endl;

		std::cout << "________________" << std::endl;
	}
}

void DataChange(Data* (&d), int n) {
	int _n{};
	std::cout << "Enter number element (from 1 to " << n << "): ";
	std::cin >> _n;
	--_n; 

	system("cls");

	if (_n >= 0 && _n < n) {
		std::cout << "Enter FIO: ";
		std::cin >> d[_n]._initial.surname;
		std::cin >> d[_n]._initial.patronymic;
		std::cin >> d[_n]._initial.name;

		std::cout << "Enter date: ";
		std::cin >> d[_n]._date.day;
		std::cin >> d[_n]._date.month;
		std::cin >> d[_n]._date.year;

		std::cout << "Enter address: ";
		std::cin >> d[_n]._adress.city;
		std::cin >> d[_n]._adress.home;

		system("cls");
		std::cout << "Data is changed!" << std::endl;
	}
	else {
		std::cout << "Number was entered wrong!" << std::endl;
	}
}

void DeleteData(Data* (&d), int& n) {
	int _n{};
	std::cout << "Enter number element (from 1 to " << n << "): ";
	std::cin >> _n;
	--_n;

	system("cls");

	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n]; 

		Copy(buf, d, n); 

		--n;
		d = new Data[n]; 
		
		int q{ 0 };

		for (int i = 0; i <= n; ++i) {
			if (i != n) { 
				d[q] = buf[i]; 
				++q;
			}
		}
		system("cls");
		delete[] buf;

		std::cout << "Data is removed!" << std::endl;

	}
	else {
		std::cout << "Number was entered wrong!" << std::endl;
	}
}

void Copy(Data* (&d_new), Data* (&d_old), int n) { 
	for (int i = 0; i < n; ++i) {
		d_new[i] = d_old[i]; 
	}
}

void Copy(Data &d_new, Data &d_old) {
	d_new._initial.surname = d_old._initial.surname;
	d_new._initial.name = d_old._initial.name;
	d_new._initial.patronymic = d_old._initial.patronymic;

	d_new._date.day = d_old._date.day;
	d_new._date.month = d_old._date.month;
	d_new._date.year = d_old._date.year;

	d_new._adress.city = d_old._adress.city;
	d_new._adress.home = d_old._adress.home;
}

void AddData(Data* (&d), int &n) {

	Data* buf = new Data[n]; 

	Copy(buf, d, n);

	++n;
	d = new Data[n];
	
	Copy(d, buf, --n); 

	std::cout << "Enter FIO: ";
	std::cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	std::cout << "Enter date: ";
	std::cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	std::cout << "Enter address: ";
	std::cin >> d[n]._adress.city >> d[n]._adress.home;

	system("cls");

	std::cout << "Data is added!" << std::endl;

	delete[] buf;
}

void DataSorting(Data* d, int n) {
	Data buf; 

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) { 
			if (d[i]._initial.surname > d[j]._initial.surname) { 
				Copy(buf, d[j]); 
				Copy(d[j], d[i]); 
				Copy(d[i], buf); 
			}
		}
	}

	std::cout << "Data is sorted!" << std::endl;
}

void SavingData(Data* d, int n, std::string fileName) { 

	std::ofstream record(fileName, std::ios::out); 

	if (record) { 
		record << n << std::endl; 
		for (int i = 0; i < n; ++i) { 
			record << d[i]._initial.surname << std::endl;
			record << d[i]._initial.name << std::endl;
			record << d[i]._initial.patronymic << std::endl;

			record << d[i]._date.day << " ";
			record << d[i]._date.month << " ";
			record << d[i]._date.year << std::endl;

			record << d[i]._adress.city << std::endl;
			if (i < n - 1) {
				record << d[i]._adress.home << std::endl;
			}
			else {
				record << d[i]._adress.home;
			}
		}
	}
	else {
		std::cout << "Error opening file!" << std::endl;
	}

	record.close();

}

void DataEmpty() {
	std::cout << "Data is empty!" << std::endl;
}
