#pragma once

#include <string>
using namespace std;

#include "Employee.h"

class Locker
{
	int id;
	string size;
	int floor;
	Employee* pEmp; 	//an Employee can use a locker [Association Relationship]

public:
	Locker(int , string, int);
	int getID();
	void AssignLocker(Employee* pE);
	void printInfo();
	~Locker();
};
