#pragma once
#include <iostream>
using namespace std;
template <class T>
class Matrix
{
//private:
protected:
	T Element[5][7];        //2-D Array
public:
	Matrix()
	{
		//Constructor
	}
	bool addValue(int row, int col, T Value)
	{
		if ((row > 4 || row < 0) || (col > 6 || col < 0))
		{
			return false;
		}
		Element[row][col] = Value;
		return true;
	}
	bool BelongTo(T Value)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (Element[i][j] == Value)
				{
					return true;
				}
			}
		}
		return false;
	}
	bool PrintRow(int row)
	{
		if (row < 0 || row > 4)
		{
			return false;
		}
		cout << "Row : " << row << endl;
		for (int j = 0; j < 7; j++)
		{
			cout << Element[row][j] << " ";
		}
		cout << endl;
		return true;
	}
	void Print()
	{
		cout << "Matrix : " << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << Element[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	T MaxValue()
	{
		T Max = Element[0][0];
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				Max = Element[i][j] > Max ? Element[i][j] : Max;
			}
		}
		return Max;
	}
	~Matrix()
	{

	}
};

