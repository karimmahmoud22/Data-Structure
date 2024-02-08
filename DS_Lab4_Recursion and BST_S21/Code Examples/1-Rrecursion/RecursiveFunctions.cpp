#include <iostream>
#include <string>
using namespace std;

//Recusive version for factorial function
int Factorial(int n)
{
	if (n == 0) return 1;
	else return n * Factorial(n - 1);
}


//Factorial_Demo
//To illustrate how factorial works
int Factorial_Demo(int n)
{
	static int cnt = 0;
	cout << endl << std::string(15*cnt++, ' ');
	cout << "Fact(" << n << ")";
	if (n == 0) {
		cnt--;  return 1;
	}
	else
	{
		cout << "==>Calls Fact(" << n - 1 << ")...";
		int Fprev = Factorial_Demo(n - 1);
		cout << endl << std::string(15 * cnt, ' ');
		cout << "<=== Fact(" << n - 1 << ") returns " << Fprev<<endl;
		cout << endl << std::string(15 * (--cnt), ' ');
		cout << "Back inside Fact(" << n << "),return "<<n<<"*Fact("<<n-1<<")";
		
		return n*Fprev;
	}
}

int RecursiveSum(int num)
{
	if (num == 0)
		return 0;
	return num + RecursiveSum(num - 1);
}

int RecursiveFibonacci( int nm)
{
	if (nm <= 2 && nm != 0)
		return 1;
	else if (nm == 0)
		return 0;
	else
		return ( RecursiveFibonacci( nm - 1) + RecursiveFibonacci( nm - 2 ) );
}

void RecursivePrintArr( int arr [] , int size )
{
	if (size == 0)
		return;
	cout << arr[5 - size] << endl;
	RecursivePrintArr ( arr  , size - 1);
}

int ZeroCount(int arr1[], int size1)
{
	if (size1 == 0)
		return 0;
	if (arr1[size1 - 1] == 0)
		return 1 + ZeroCount( arr1 ,  size1 - 1 );
	else
		return  ZeroCount(arr1, size1 - 1);
}

int GetMin(int arr2[], int size2)
{
	static int minn = arr2[size2 - 1];
	if (size2 == 1)
		return minn;
	if (minn > arr2[size2 - 2])
		minn = arr2[size2 - 2];
	return GetMin(arr2, size2 - 1);
}

/*
float GCD(int n, int m)
{
	if ( n % m == 0 )
		return n / m;
	return GCD(m, n % m);
}
*/

/*
int Digits(int numm)
{


	return Digits(numm);
}
*/

int main()
{
	/*
	int n = 5;
	cout << "Main calls Fact(" << n << ")";
	int x = Factorial_Demo(n);
	cout << "\n\nFact(" << n << ") returns " << x << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	cout << "**********RecursiveSum_Test**********" << endl;
	int nn , kk;
	cin >> nn;
	kk = RecursiveSum(nn);
	cout << kk << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	cout << "**********RecursiveFibonacci_Test**********" << endl;
	int nnn, kkk;
	cin >> nnn;
	kkk = RecursiveFibonacci(nnn);
	cout << kkk << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	cout << "**********RecursivePrintArr_Test**********" << endl;
	int arr[5];
	arr[0] = 2;
	arr[1] = 4;
	arr[2] = 6;
	arr[3] = 8;
	arr[4] = 10;
	RecursivePrintArr( arr  , 5);
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	cout << "**********ZeroCount_Test**********" << endl;
	int arr[5];
	int y;
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 10;
	arr[4] = 10;
	y = ZeroCount(arr, 5);
	cout << y << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	cout << "**********GetMin_Test**********" << endl;
	int arr[5];
	int y , minn;
	arr[0] = 1;
	arr[1] = 5;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = -2;
	y = GetMin( arr , 5 );
	cout << y << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	//*************************************NOT COMPLETED YET*************************************
	cout << "**********GCD_Test**********" << endl;
	int num1, num2;
	cin >> num1 >> num2;
	float r = GCD(num1, num2);
	cout << r << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	/*
	//*************************************NOT COMPLETED YET*************************************
	cout << "**********Digits_Test**********" << endl;
	int num11;
	cin >> num1 >> num2;
	float rr = Digits(num1, num2);
	cout << rr << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	*/

	char c;
	cin >> c;
	return 0;
	
}