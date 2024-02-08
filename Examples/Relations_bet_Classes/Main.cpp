#include "Locker.h"
#include "Dept.h"

#include <iostream>
using namespace std;


int main()
{
	//Class Employee contains and OBJECT of class Date as a member (DOB is part of EMP and is related to it Composition)
	//==> When an obj of EMP is constructed, an obj of Date is also constructed
	Employee* pE1 = new Employee("Ahmed", 12345, 25, 12, 1975); 
	pE1->PrintData();

	
	Employee* pE2 = new Employee("Hossam", 102030, 30, 5, 1980); 
	pE2->PrintData();

	//Class Locaker has a pointer to class Employee as a member (Locaker is used by EMP ==> Association)
	//==> When an obj of Locker is constructed, NO EMP obj is constructed
	Locker* pL= new Locker(1000, "small", 3); 
	pL->printInfo();
	pL->AssignLocker(pE1);
	pL->printInfo();

	//Class Dept has a pointer to class Employee as a member (Dept contains EMP ==> Aggregation)
	//==> When an obj of Dept is constructed, NO EMP obj is constructed
	Dept* pD=new Dept("R&D");
	pD->printData();
	pD->ChangeManager(pE1);
	pD->printData();
	pD->ChangeManager(pE2);
	pD->printData();

	string tmp;

	//Destructing objects
	delete pD;	//destructing Dept obj does NOT destruct EMP obj (as it is Aggregation)
	cout<<"\nPress any key to continue";
	getline(cin,tmp);
	delete pE2; //destructing EMP obj destructs Date obj (as it is composition)
	cout<<"\nPress any key to continue";
	getline(cin,tmp);
	delete pL; //destructing Locker obj does NOT destruct EMP obj (as it is Association)
	cout<<"\nPress any key to continue";
	getline(cin,tmp);
	delete pE1;//destructing EMP obj destructs Date obj (as it is composition)


	return 0;
}
