#include "Functions.h"

void DataEntry(Data* (&d), int& n) { 

	Initials initials{};
	Date date{};
	Address address{};

	std::cout << "Enter size array: ";
	std::cin >> n;

	d = new Data[n]; 

	for (int i = 0; i < n; ++i) { 
		std::cout << "Enter FIO: ";
		std::cin >> initials.surname >> initials.name >> initials.patrinymic;

		std::cout << "Enter date: ";
		std::cin >> date.day >> date.month >> date.year;

		std::cout << "Enter address: ";
		std::cin >> address.city >> address.home;

		d[i].DataEntry(initials, date, address);

		std::cout << "_____________" << std::endl;
	}
}

void DataReading(Data* (&d), int& n, std::string fileName) {
	
	std::ifstream reading(fileName); 

	if (reading) {

		Initials initials{}; 
		Date date{};
		Address address{};

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; ++i) {
			reading >> initials.surname >> initials.name >> initials.patrinymic;
			reading >> date.day >> date.month >> date.year;
			reading >> address.city >> address.home;

			d[i].DataEntry(initials, date, address);
		}
		std::cout << "Data is readed!" << std::endl;
	}
	else {
		std::cout << "Error is opened file! " << std::endl;
	}

	reading.close();
}

void Print(Data* d, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << "Data " << i + 1 << std::endl;

		d[i].Print(); 

		std::cout << "__________________" << std::endl;
	}
}

void DataChange(Data* (&d), int& n) {

	Initials initials{}; 
	Date date{};
	Address address{};
	int _n{};

	std::cout << "Enter number element (from 1 to " << n << "): ";
	std::cin >> _n;
	--_n;

	if (_n >= 0 && _n < n) {
		std::cout << "Enter FIO: ";
		std::cin >> initials.surname >> initials.name >> initials.patrinymic;

		std::cout << "Enter date: ";
		std::cin >> date.day >> date.month >> date.year;

		std::cout << "Enter address: ";
		std::cin >> address.city >> address.home;

		d[_n].DataEntry(initials, date, address); 
	}
	else {
		std::cout << "Number is written wrong!" << std::endl;
	}
}

void Copy(Data* d_new, Data* d_old, int n) {

	for (int i = 0; i < n; ++i) {
		d_new[i] = d_old[i];
	}
}

void AddData(Data* (&d), int& n) {

	Initials initials{};
	Date date{};
	Address address{};
	Data* buf = new Data[n];
	int size = n; 
	int new_size = ++n; 

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size); 

	std::cout << "Enter FIO; ";
	std::cin >> initials.surname >> initials.name >> initials.patrinymic;

	std::cout << "Enter date: ";
	std::cin >> date.day >> date.month >> date.year;

	std::cout << "Enter address: ";
	std::cin >> address.city >> address.home;

	d[size].DataEntry(initials, date, address);

	std::cout << "Data is added!" << std::endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n) {
	int _n{};
	Data* buf = new Data[n];

	std::cout << "Enter number element: ";
	std::cin >> _n;
	--_n;

	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q{}; 
		--n;

		d = new Data[n]; 

		for (int i = 0; i <= n; ++i) {
			if (i != n) { 
				d[q] = buf[i]; 
				++q;
			}
		}

		std::cout << "Data is deteled!" << std::endl;
	}
	else {
		std::cout << "Number is written wrong!" << std::endl;
	}

	delete[] buf;
}

void SortingData(Data* d, int n) {

	Data buf; 
	int numOfSorted{}; 

	for (int i = 0; i < n; ++i) { 
		for (int j = i + 1; j < n; ++j) { 
			if (d[i].GetInitials().surname > d[j].GetInitials().surname) {
				buf = d[i]; 
				d[i] = d[j];
				d[j] = buf;

				++numOfSorted;
			}
		}
	}

	std::cout << "Data is sorted! Number of sorting: " << numOfSorted << std::endl;
}

void SaveData(Data* d, int n, std::string fileName) {

	std::ofstream record (fileName);

	if (record) {
		record << n << std::endl; 

		for (int i = 0; i < n; ++i) {
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patrinymic << std::endl;
			record << d[i].GetDate().day << " " << d[i].GetDate().month << " " << d[i].GetDate().year << std::endl;
			record << d[i].GetAddress().city << d[i].GetAddress().home;

			if (i < n - 1) { 
				record << std::endl;
			}
		}
	}
	else {
		std::cout << "Error is opened file!" << std::endl;
	}
	
	std::cout << "Data is saved in file: " << fileName << std::endl;

	record.close();
}

void DataEmpty() {
	std::cout << "Data is empty!" << std::endl;
}
