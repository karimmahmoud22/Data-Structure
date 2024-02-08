#pragma once
#include "Matrix.h"
#include "Date.h"

class DateMatrix
	: public Matrix<Date>
{
public:
	bool BelongTo(Date Value)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (Element[i][j].GetYear() == Value.GetYear())
				{
					if (Element[i][j].GetMonth() == Value.GetMonth())
					{
						if (Element[i][j].GetDay() == Value.GetDay())
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool PrintRow(int row)    //(Year,Month,Day)
	{
		if (row < 0)
		{
			return false;
		}
		cout << "Row : " << row << endl;
		for (int j = 0; j < 7; j++)
		{
			//cout << Element[row][j] << " ";
			cout << "(" << Element[row][j].GetYear() << "," << Element[row][j].GetMonth() << ","
				<< Element[row][j].GetDay() << ")" << " ";
		}
		cout << endl;
		return true;
	}
	void Print()         //(Year,Month,Day)
	{
		cout << "Matrix : " << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "(" << Element[i][j].GetYear() << "," << Element[i][j].GetMonth() << ","
					<< Element[i][j].GetDay() << ")" << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	Date MaxValue()
	{
		
		Date Max = Element[0][0];

		bool Cond1, Cond2, Cond3, Cond4, Cond5;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				//best practice instead of nested if
				Cond1 = Element[i][j].GetYear() > Max.GetYear();
				Cond2 = Element[i][j].GetYear() == Max.GetYear();
				Cond3 = Element[i][j].GetMonth() > Max.GetMonth();
				Cond4 = Element[i][j].GetMonth() == Max.GetMonth();
				Cond5 = Element[i][j].GetDay() > Max.GetDay();

				if (Cond1)
					Max = Element[i][j];
				if (Cond2 && Cond3)
					Max = Element[i][j];
				if (Cond2 && Cond4 && Cond5)
					Max = Element[i][j];


				////the solution with nested if

				//Max = Element[i][j] > Max ? Element[i][j] : Max;
				/*if (Element[i][j].GetYear() > Max.GetYear())
				{
					Max = Element[i][j];
				}
				else
				{
					if (Element[i][j].GetYear() == Max.GetYear())
					{
						if (Element[i][j].GetMonth() > Max.GetMonth())
						{
							Max = Element[i][j];
						}
						else
						{
							if (Element[i][j].GetMonth() == Max.GetMonth())
							{
								if (Element[i][j].GetDay() > Max.GetDay())
								{
									Max = Element[i][j];
								}
							}
						}
					}
				}*/
			}
		}
		return Max;
	}
};

