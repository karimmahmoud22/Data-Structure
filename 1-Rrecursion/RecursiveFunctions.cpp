#include <iostream>
#include <string>
using namespace std;

void HelloWorld(int count)
{
	if (count < 1)return;
	cout << "Hello World!" << endl;
	HelloWorld(count - 1);
}
int Factorial(int n)
{
	cout << "\nFactorial(" << n << ") is called";
	if (n == 0) return 1;
	else
	{
		cout << " ==> Call Factorial(" << n - 1 << ")";
		int Fprev = Factorial(n - 1);
		cout << " \n <=== Factorial(" << n - 1 << ") returns " << Fprev;
		return n*Fprev;
	}
}

//The above version is for illustration
//Factorial should be written as
//int Factorial(int n)
//{
//	if (n == 0) return 1;
//	else return n * Factorial(n - 1);
//}


int main()
{
	int n = 7;
	HelloWorld(n);
	int x = Factorial(n);
	cout << "\n\nmain call::Factorial of " << n << " is " << x << endl;
	string s;
	getline(cin, s); //just to pause console (output) screen
	return 0;
	
}