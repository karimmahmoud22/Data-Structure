#pragma once
#include"StackADT.h"

class Car
{
private:
	int CarNumber;
	int EngineNumber;
public:
	Car( int car = 0 , int eng = 0 )
	{
		SetCarNumber(car);
		SetCarEngine(eng);
	}

	void SetCarNumber( int car )
	{
		CarNumber = (car > 0) ? car : 0;
	}
	void SetCarEngine( int eng )
	{
		EngineNumber = (eng > 0) ? eng : 0;
	}

	~Car()
	{

	}
};