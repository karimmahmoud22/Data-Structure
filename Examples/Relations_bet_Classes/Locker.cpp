#include "Locker.h"
#include <iostream>
using namespace std;

Locker::Locker(int ID, string s, int f)
{
	cout<<"\n||| Locker Constructor called... |||";
	id = ID;
	size = s;
	floor = f;
	pEmp = nullptr;
}

int Locker::getID()
{
	return id;
}

void Locker::AssignLocker(Employee* pE)
{
	pEmp = pE;
}

void Locker::printInfo()
{
	cout<<"\n\nLocker Info:";
	cout<<"\nID = "<<id<<", size is: "<<size<<", at floor no. "<<floor;
	if(pEmp)
	{
		cout<<"\nlocker is assigned to the following Employee...";
		pEmp->PrintData();
	}
	else
		cout<<"\nLocker NOT assigned";

}

Locker::~Locker()
{
	cout<<"\n~~~ Date Destructor called ~~~";
}


