#pragma once

#include <string>
using namespace std;

#include "Employee.h"

//class Department
class Dept
{
	string name;
	Employee* pManager;	//each department has a manager [Aggregation Relationship]
public:
	Dept(string m_name);
	void printData();
	void ChangeManager(Employee* pM);
	~Dept();

};
