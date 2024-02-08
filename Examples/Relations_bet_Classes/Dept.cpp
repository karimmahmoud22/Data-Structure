#include "Dept.h"

#include <iostream>
using namespace std;

Dept::Dept(string m_name)
{
	cout<<"\n||| Dept Constructor called... |||";
	name = m_name;
	pManager = nullptr;
}

void Dept::ChangeManager(Employee* pM)
{
	pManager = pM;
}



void Dept::printData()
{
	cout<<"\n\Department Info:";
	cout<<"\nName is "<<name;
	if(pManager)
	{
		cout<<"\nDept manager info:";
		pManager->PrintData();
	}
	else
		cout<<"\nDept has no manager yet";

}


Dept::~Dept()
{
	cout<<"\n~~~ Dept Destructor called ~~~";
}

