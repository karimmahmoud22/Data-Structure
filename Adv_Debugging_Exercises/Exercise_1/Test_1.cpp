#include <iostream>
using namespace std;

#include "Complex.h"

#define MAX_SIZE 1000

void PrintAll(Complex ** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->Print();
	}
}

void ClearAll(Complex ** arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete arr[i];
	}
}

int main()
{
	Complex * ComplexPList [MAX_SIZE];
	int actualSize = 0;

	// initialize all the pointer of the list with NULL
	for (int i = 0; i < MAX_SIZE; i++)
	{
		ComplexPList[i] = NULL;
	}

	// TEST 1
	cout << "\nAdding Complex Numbers ..." << endl;
	char cont = 'y';
	while (cont == 'y')
	{
		ComplexPList[actualSize] = new Complex;
		actualSize++;

		ComplexPList[actualSize]->ReadInfo();

		cout << "Enter y if you want to add another complex (to exit, press any char else): ";
		cin >> cont;
	}

	// TEST 2
	PrintAll(ComplexPList, MAX_SIZE); 

	// TEST 3
	int dindex;
	cout << "Please enter an index to delete its object: ";
	cin >> dindex;

	delete ComplexPList[dindex];
	actualSize--;

	ClearAll(ComplexPList, actualSize);

	// TEST 4
	char * name = NULL;
	cout << strlen(name);

}