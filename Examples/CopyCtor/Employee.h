#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee 
{
private:
    string job;
    string name;
	double *LastPromotion;
public:
    Employee(string n, string j);
    ~Employee();
    string getName() const;
	void setName(string);
	string getJob() const;
	void setJob(string);
	void setLastProm(double );
	
	void PrintInfo();

	//The copy constructor 
	//Checkpoint[3]::uncomment next prototype and uncomment its def in .cpp file
	//Also uncomment all other checkpoints
	//Employee(const Employee &rhs);


};

#endif