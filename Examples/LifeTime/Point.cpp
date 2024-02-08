#include "Point.h"
#include <iostream>
using namespace std;


Point::Point(double a, double b)
{
	x = a;
	y = b;
	cout<<endl<<"||| Point ("<<x<<","<<y<<") is being constructed |||";
}


Point::~Point()
{
	cout<<endl<<"~ ~ ~ ~ Point ("<<x<<","<<y<<") is being destructed ~ ~ ~ ~\n";
}

void Point::setX(double a)
{
	x = a;
}

double Point::getX()
{
	return x;
}

void Point::setY(double b)
{
	y = b;
}

double Point::getY()
{
	return y;
}

void Point::print()
{
	cout<<endl<<"Print Point ("<<x<<","<<y<<")\n";
}
