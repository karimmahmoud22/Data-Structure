#include "Point.h"
#include <iostream>
using namespace std;

/*
 *
 *	Notice that the code has some checkpoints
 *	Please follow them in order
 *
*/

Point* test(Point , Point& , Point* );


int main()
{
	//After 1st run, 
	//uncomment the code according to the numbers shown in square brackets

	//Checkpoint [1] ==> uncomment next line. ==> What is the problem? Solution?
	//Point P;
	
	//Automatic objects
	Point P1(1,1);
	Point P2(2,2);

	//Dynamic object
	//Checkpoint [3] ==> uncomment next line, and Re-run
	//Point* P3= new Point(3,3);

	cout<<endl;

	//Checkpoint [2] ==> Uncomment (if statement), and Re-run
	/*
	if(true)
	{
		//Object defined in certain scope.
		Point P4(4,4);
		//Checkpoint [4] ==> uncomment next line, and Re-run
		//delete P3;        //the destructor for P3 is called here
	}	   //the destructor for P4 is called here
	                    
	cout<<"after 'if' block\n";
	*/

	Point P5(5,5);


	cout<<endl;
		
	Point* Ptr6;	//This line does NOT create any objects (why?)

	//Checkpoint [5] ==> uncomment next block, and Re-run,
	// Q: Can you explain each printed line? 
	/*
	Ptr6=test(P1,P2,&P5);

	P1.print();
	P2.print();
	P5.print();
	Ptr6->print();
	*/
	
	cout<<endl;	

	return 0;
}


Point* test(Point A, Point& R, Point* ptr)
{
	//When function is called as: test(P1,P2,&P5)
	//A  is a copy of P1
	//R is an alias for P2
	//ptr is a pointer to P5
	//So,  A = (1, 1), R = (2, 2), prt points to (5, 5)

	//Point (1, 1) is updated to (10, 10)
	A.setX(10);
	A.setY(10);

	//Point (2, 2) is updated to (20, 20)
	R.setX(20);
	R.setY(20);

	//Point (5, 5) is updated to (30, 30)
	ptr->setX(30);
	ptr->setY(30);
	
	Point P(40 , 40);	//Create a point (40, 40)
	
	Point *M = new Point(50, 50);  //Allocate point (50, 50)
	return M;
}