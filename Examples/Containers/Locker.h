#pragma once

#include <string>
using namespace std;

#include "Employee.h"

class Locker
{
	
	string size;
	int floor;
	Employee* pEmp; 	//a locker can be assigned to an EMP

public:
	Locker(string s="small", int f=2);
	
	void AssignLocker(Employee* pE);
	void printInfo();
	
};
