#pragma once

class Date
{
	int day, month, year;
public:
	Date(int d,int m,int y);	//non-default ctor
	void setDate(int d,int m,int y);
	int getDay();
	int getMonth();
	int getYear();
	~Date();
};
