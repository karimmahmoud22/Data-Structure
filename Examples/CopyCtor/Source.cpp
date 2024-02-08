#include <string>
#include <iostream>
using namespace std;
#include "Employee.h"

void printProgrammerData(Employee E)	//E is passed by value
{
	cout<<"\n\nFunction printProgrammerData called...";
	if(E.getJob() == "programmer")
		E.PrintInfo();
	cout<<"\nFunction printProgrammerData Exiting\n";
}

int main()
{

    Employee E1("Ahmed","programmer");
	E1.setLastProm(100);

	E1.PrintInfo();

	//Checkpoint[1]: after 1st run, uncomment next line and re-run
	//printProgrammerData(E1);
	
	cout<<endl<<"After function returns..."; 
	E1.PrintInfo();

	//Checkpoint[2]: comment checkpoint[1] again
	//then uncomment next block and re-run
	/*
	Employee E2=E1;
	E1.PrintInfo();
	E2.PrintInfo();
	*/


	//Without copy constructor the two objects are referencing the same memory allocated
	//for "name" when the second object "manager" is destructed this memory is deallocated 
	//so when the object "programmer" is to be destrcuted the memory for name is already deallocated.
	
	return 0;
} 