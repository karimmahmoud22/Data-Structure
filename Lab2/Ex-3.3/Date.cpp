#include "Date.h"

Date::Date()
{

}

Date::Date(int y, int m, int d)
{
	SetDay(d);
	SetMonth(m);
	SetYear(y);
}

void Date::SetDay(int d)
{
	day = d > 0 ? d : 0;
}

void Date::SetMonth(int m)
{
	month = m > 0 ? m : 0;
}

void Date::SetYear(int y)
{
	year = y > 0 ? y : 0;
}

int Date::GetDay()
{
	return day;
}

int Date::GetMonth()
{
	return month;
}

int Date::GetYear()
{
	return year;
}

bool Date::operator==(Date D)
{
	if (year == D.year)
	{
		if (month == D.month)
		{
			if (day == D.day)
			{
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>(Date D)
{
	if (year > D.year)
	{
		return true;
	}
	else
	{
		if (year == D.year)
		{
			if (month > D.month)
			{
				return true;
			}
			else
			{
				if (month = D.month)
				{
					if (day > D.day)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

Date::~Date()
{

}
