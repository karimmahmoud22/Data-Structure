#include "Employee.h"
#include <iostream>
using namespace std;
#include <string.h>


Employee::Employee(string Name, int m_id, int d, int m, int y):DOB(d, m, y)
{	
    id = m_id;
	name = Name;
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


 



