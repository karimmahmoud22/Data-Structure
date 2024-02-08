#include <iostream>
#include "DateMatrix.h"
using namespace std;

void main()
{
	//Testing for Matrix<Date> -- Template Inheritance
	DateMatrix MDate;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			MDate.addValue(i, j, Date(i, j, i * j));         //(Year,Month,Day)
		}
	}
	MDate.Print();
	Date X(2, 5, 10);
	if (MDate.BelongTo(X))
	{
		cout << "Date (2,5,10) Belongs to this matrix"
			<< endl;
	}
	else
	{
		cout << "Date (2,5,10) Doesn't belong to this matrix"
			<< endl;
	}
	cout << "Max = " << "(";
	cout << MDate.MaxValue().GetYear() << ","
		<< MDate.MaxValue().GetMonth() << ","
		<< MDate.MaxValue().GetDay() << ")" << endl;
}