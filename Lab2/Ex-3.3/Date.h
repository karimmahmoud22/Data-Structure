#pragma once
class Date    //This is a simple date class just meant to test things out
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int y, int m, int d);
	void SetDay(int d);
	void SetMonth(int m);
	void SetYear(int y);
	int GetDay();
	int GetMonth();
	int GetYear();
	bool operator == (Date D);
	bool operator > (Date D);
	~Date();
};

