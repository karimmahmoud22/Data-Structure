#include "Point.h"
#include <iostream>
using namespace std;

//Default constructor
Point::Point()
{
	cout<<"\n\nctor Point() is called";
	x = 0;
	y = 0;
	z = 0;
	cout<<endl<<"Point ("<<x<<","<<y<<","<<z<<") is being constructed";
}

//Constructor with two arguments (notice that default value for parameter is written in the header file not here)
Point::Point(double a, double b)
{
	cout<<"\n\nctor Point(double, double) is called";
	x = a;
	y = b;
	z = 0;
	cout<<endl<<"Point ("<<x<<","<<y<<","<<z<<") is being constructed";
}

//Constructor with three arguments
Point::Point(double a, double b, double c)
{
	cout<<"\n\nctor Point(double, double, double) is called";
	x = a;
	y = b;
	z = c;
	cout<<endl<<"Point ("<<x<<","<<y<<","<<z<<") is being constructed";
}

//Destructor
Point::~Point()
{
	cout<<endl<<"\n~~ Destructing Point ("<<x<<","<<y<<","<<z<<")";
}

