#include "Functions.h"

int _stateMenu{};

void Menu() {
	std::cout << "Select action: " << std::endl
		<< "(0) Exit with program" << std::endl
		<< "(1) Enter data" << std::endl
		<< "(2) Output" << std::endl
		<< "(3) Change" << std::endl
		<< "(4) Delete" << std::endl
		<< "(5) Add" << std::endl
		<< "(6) Sort" << std::endl
		<< "(7) Save" << std::endl
		<< "Your select: ";
	std::cin >> _stateMenu;
}

int main()
{
	Menu();

	int _actions{};
	int amountOfData = 0;
	std::string fileName{};

	Data* d = new Data[amountOfData];

	while (_stateMenu != 0) {
		switch (_stateMenu){
		case 1:
			system("cls");

			std::cout << "Enter manually(1) or from file?: " ;
			std::cin >> _actions;

			system("cls");

			if (_actions == 1) { 
				DataEntry(d, amountOfData);
			}
			else {
				ReadingData(d, amountOfData, "Input.txt");
			}

			system("pause");
			system("cls");
			Menu();
			break;

		case 2:
			system("cls");

			if (amountOfData != 0) { 
				Print(d, amountOfData);
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
			if (amountOfData != 0) {
				DataChange(d, amountOfData);
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

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
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

			if (amountOfData != 0) {
				AddData(d, amountOfData);
				++amountOfData;
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

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
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

			std::cout << "Enter name file: ";
			std::cin >> fileName;

			if (amountOfData != 0) {
				SavingData(d,amountOfData, fileName);
			}
			else {
				DataEmpty();
			}

			system("pause");
			system("cls");
			Menu();
			break;
		default:
			std::cout << "Number was written wrong!" << std::endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
	}

	return 0;
}
