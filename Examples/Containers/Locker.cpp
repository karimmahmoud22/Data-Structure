#include "Locker.h"
#include <iostream>
using namespace std;

Locker::Locker(string s, int f)
{	
	size = s;
	floor = f;
	pEmp = nullptr;
}



void Locker::AssignLocker(Employee* pE)
{
	pEmp = pE;
}

void Locker::printInfo()
{
	cout<<"\n\nLocker Info:";
	cout<<"\n size is: "<<size<<", at floor no. "<<floor;
	if(pEmp)	//pEmp is not NULL
	{
		cout<<"\nlocker is assigned to the following Employee...";
		pEmp->PrintData();
	}
	else
		cout<<"\nLocker NOT assigned";

}




