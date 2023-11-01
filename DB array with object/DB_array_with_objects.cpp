#include "Functions.h"
#include "Data.h"

int _stateMenu{};

void Menu() {
	std::cout << "Select the action: " << std::endl
		<< "(0) Exit with program" << std::endl
		<< "(1) Input data" << std::endl
		<< "(2) Output data" << std::endl
		<< "(3) Change data" << std::endl
		<< "(4) Add data" << std::endl
		<< "(5) Delete data" << std::endl
		<< "(6) Sort data" << std::endl
		<< "(7) Save data" << std::endl
		<< "Your choose: ";
	std::cin >> _stateMenu;
}


int main()
{
	Menu();
	int _actions{};
	std::string fileName;

	int _size{ 0 };
	Data* d = new Data[_size];


	while (_stateMenu !=0 ) {
		switch (_stateMenu) {
		case 1: 
			system("cls");

			std::cout << "Enter data manually (1) or write with file (any)?: ";
			std::cin >> _actions;

			if (_actions == 1) {
				DataEntry(d, _size);
			}
			else {
				DataReading(d, _size, "Input.txt");
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (_size != 0) {
				Print(d, _size);
			}
			else {
				DataEmpty();
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			if (_size != 0) {
				DataChange(d, _size);
			}
			else {
				DataEmpty();
			}
			
			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			if (_size != 0) {
				AddData(d, _size);
			}
			else {
				DataEmpty();
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			if (_size != 0) {
				DeleteData(d,_size);
			}
			else {
				DataEmpty();
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");

			if (_size != 0) {
				SortingData(d, _size);
			}
			else {
				DataEmpty();
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 7:
			system("cls");

			if (_size != 0) {
				SaveData(d, _size, "Out.txt");
			}
			else {
				DataEmpty();
			}

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			std::cout << "Data is written wrong!" << std::endl;
			system("cls");
			Menu();
			break;
		}
	}

	system("cls");
	std::cout << "Work is completed!" << std::endl;
	system("pause");

	return 0;
}

