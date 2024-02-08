#include <iostream>
using namespace std;

template <class T>
T ArrMin(T* Arr, int N)
{
	T Min = Arr[0];
	for (int i = 1; i < N; i++)
	{
		Min = Arr[i] < Min ? Arr[i] : Min;
	}
	return Min;
}

void main()
{
	//for integers
	int A[6] = {1,2,3,4,5,6};
	int Min1 = ArrMin<int>(A, 6);
	cout << Min1 << endl;

	//for char
	char B[6] = { 'j','b','c','d','e','f' };
	char Min2 = ArrMin<char>(B, 6);
	cout << Min2<<endl;

}