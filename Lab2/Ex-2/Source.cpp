#include <iostream>
#include "Matrix.h"
using namespace std;

void main()
{
	//1-Testing for Matrix<int>
   /*	Matrix<int> MI;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			MI.addValue(i, j, i * j);
		}
	}
	MI.Print();
	MI.PrintRow(4);
	int X;
	cin >> X;
	if (MI.BelongTo(X))
	{
		cout << X << " Belongs to this matrix"
			<< endl;
	}
	else
	{
		cout << X << " Doesn't Belong to this matrix"
			<< endl;
	}
	cout << "Max = " << MI.MaxValue() << endl;*/
	//2-Testing for Matrix<string>
	/*Matrix<string> MS;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			MS.addValue(i, j,"A");
		}
	}
	MS.addValue(0, 0, "Hossam");
	MS.addValue(1, 1, "Tarek");
	MS.addValue(2, 2, "Abdullah");
	MS.addValue(3, 3, "Essam");
	MS.addValue(4, 4, "Abdelrahman");
	MS.Print();
	MS.PrintRow(3);
	if (MS.BelongTo("Essam"))
	{
		cout << "Essam Belongs to this matrix"
			<< endl;
	}
	else
	{
		cout << "Essam Doesn't belong to this matrix"
			<< endl;
	}
	cout << "Max = " << MS.MaxValue() << endl;               //compares between strings using their asci code*/
	//3-Testing for Matrix<double>
	/*Matrix<double> MD;
	for (double i = 0; i < 5; i++)
	{
		for (double j = 0; j < 7; j++)
		{
			MD.addValue(i, j, i * j*.3);
		}
	}
	MD.Print();
	MD.PrintRow(3);
	double Y;
	cin >> Y;
	if (MD.BelongTo(Y))
	{
		cout << Y << " Belongs to this matrix"
			<< endl;
	}
	else
	{
		cout << Y << " Doesn't Belong to this matrix"
			<< endl;
	}
	cout << "Max = " << MD.MaxValue() << endl;*/
}