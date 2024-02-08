#include "Employee.h"
#include <iostream>
using namespace std;
#include <string.h>


Employee::Employee():DOB(1, 1, 1990), id(1)
{
	cout<<"\n||| Employee Def Constructor called... |||";

	DOB.setDate(1, 1, 2000);
    id = 1;
    name = ""; 
}


Employee::Employee(string Name, int m_id, int d, int m, int y):DOB(d, m, y)
{
	cout<<"\n||| Employee Constructor called... |||";

	DOB.setDate(d, m, y);
    id = m_id;
	name = Name;
}

Employee::~Employee()
{
	cout<<"\n~~~ Employee Destructor called ~~~";
}

void Employee::setName(string m_name)
{
	name= m_name;
}
string Employee::getName() const
{
	return name;
}

void Employee::setId(int m_id)
{
	id=m_id;
}
int Employee::getId() const
{
	return id;
}


void Employee::PrintData()
{
	cout<<"\n\nEmployeer data:";
	cout<<"\nName: "<<name<<", ID="<<id<<" DOB ("<<DOB.getDay()<<"/"<<DOB.getMonth()<<"/"<<DOB.getYear()<<")";
}






