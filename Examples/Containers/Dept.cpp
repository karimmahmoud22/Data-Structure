#include "Dept.h"

#include <iostream>
using namespace std;

Dept::Dept(int maxE, int maxL)
{
	cout<<"\n||| Dept Constructor called... |||";
	LocList = new Locker[maxL];		//dynamically allocate array of objects
	EmpList = new Employee* [maxE]; //dynamically allocate array of pointers
	EmpCount = 0;	//no employees are hired yet
	LockerMax = maxL;
	EmpMax = maxE;

}

bool Dept::Hire(Employee* pE)
{
	if(EmpCount == EmpMax )	//max EMP are hired
		return false;
	Employee* pCheck = FindEmp(pE->getId());
	if(pCheck)	//EMP already exists in the Dept
		return false;

	EmpList[EmpCount] = pE;	//Assign first free pointer to pE
	EmpCount++;
}


Employee* Dept::FindEmp(int EmpID)
{
	for(int i=0; i<EmpCount; i++)
		if(EmpList[i]->getId() == EmpID)   //EmpList[i] is a pointer, so use arrow operator  "->"
			return EmpList[i];

	return nullptr;	//EMP with given ID not found;
}


bool Dept::Assign(int index, int EmpID)	//assign a locker at certain index to an EMP (if found)
{
	if(index > LockerMax -1)
		return false;
	Employee* pE = FindEmp(EmpID);
	if( !pE )
		return false;

	LocList[index].AssignLocker(pE);   //LocList[i] is an object, so use dot operator "."
}



void Dept::printData()
{
	cout<<"\n\n==========================================================\nDepartment Info:";
	cout<<"\nNo. of Lockers = "<<LockerMax<<", no. of EMPs ="<<EmpCount;
		 
	cout<<"\nDept Employees info:";
	if(EmpCount > 0)
		for(int i=0; i< EmpCount; i++)
			EmpList[i]->PrintData();       //EmpList[i] is a pointer, so use arrow operator  "->"
	else
		cout<<" No Employees are hired";

	cout<<"\nDept Lockers info:";
	for(int i=0; i< LockerMax; i++)
		LocList[i].printInfo();      //LocList[i] is an object, so use dot operator "."
}


Dept::~Dept()
{
	cout<<"\n~~~ Dept Destructor called ~~~";
	delete [] LocList;
	delete [] EmpList;
}

