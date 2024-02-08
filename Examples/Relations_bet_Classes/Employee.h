#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

#include "Date.h"


class Employee 
{
private:
    int id;
    string name;
	Date DOB;	//date of birth [Compisistion Relationship]

public:
	Employee();	//default ctor
    Employee(string Name, int id, int d, int m, int y);
    ~Employee();
    string getName() const;
	void setName(string);
	int getId() const;
	void setId(int);
	void PrintData();
};

#endif