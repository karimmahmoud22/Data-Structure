#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int d,int m,int y)
{
	cout<<"\n||| Date Constructor called... |||";
	setDate(d, m ,y);
}

void Date::setDate(int d,int m,int y)
{
    if((m < 1||m > 12)||(d < 1||d > 31)||(y < 1900||y > 2020))
    {
        month = 1;
        day = 1;
        year = 2000;

    }
    else
    {
        month = m;
        day = d;
        year = y;
    }
}

Date::~Date()
{
	cout<<"\n~~~ Date Destructor called ~~~";
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}
