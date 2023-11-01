#pragma once

#include "Data.h"

void DataEntry(Data* (&d), int& n);
void DataReading(Data* (&d), int& n, std::string fileName);
void Print(Data* d, int n);
void DataChange(Data* (&d), int& n); 
void Copy(Data* d_new, Data* d_old, int n);
void AddData(Data* (&d), int& n);
void DeleteData(Data* (&d), int& n);
void SortingData(Data* d, int n);
void SaveData(Data* d, int n, std::string fileName);
void DataEmpty();
