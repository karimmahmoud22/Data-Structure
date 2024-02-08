#pragma once

#include <string>
using namespace std;

#include "Employee.h"
#include "Locker.h"

//class Department
class Dept
{	
	int EmpCount, EmpMax, LockerMax;
	Employee** EmpList;	//Will hold array of POINTERS to EMP.
	Locker* LocList; //Will hold array of OBJECTS of class Locker.
public:
	Dept(int maxE, int maxL);
	void printData();
	bool Hire(Employee* pE);
	//bool Fire(int id);
	bool Assign(int index, int EmpID);	//assign a locker to an employee
	Employee* FindEmp(int id);	//seraches for cerrain EMP given ID
	~Dept();

};
