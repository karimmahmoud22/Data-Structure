#pragma once
#include "MYPAIR.h"
#include <iostream>
using std::cout;

template <typename keyT,typename valueT = keyT, int n = 100>
class myMap {
	mypair<keyT, valueT> arr[n];
	int count;
public:
	myMap();
	myMap(mypair<keyT, valueT> ARR[], int size);
	void addPair(mypair<keyT, valueT>);
	int Count();
	bool updateValue(keyT,valueT);
	void displayMap();
	void deletePair(mypair < keyT, valueT>);


	//The thing is : we want the function to return a both a value (of type valueT) and false ( of type bool)
	//so the return type should not be simply ValueT , it should be a type that is both ValueT and Bool 
	//( to be able to contain values of type ValueT and values of type Bool)
	mypair<valueT,bool> getValue(keyT);

};

template<typename keyT, typename valueT, int n>
inline myMap<keyT, valueT, n>::myMap()
{
	count = 0;
}

template<typename keyT, typename valueT, int n>
inline myMap<keyT, valueT, n>::myMap(mypair<keyT, valueT> ARR[], int size)
{
	if (size <= 0) count = 0;
	else {
		count = size;
		for (int i = 0; i < size; ++i) {
			arr[i] = ARR[i];
		}
	}
}

template<typename keyT, typename valueT, int n>
inline void myMap<keyT, valueT, n>::addPair(mypair<keyT, valueT> x)
{
	if (count < n) {
		arr[count] = x;
		count++;
	}
}

template<typename keyT, typename valueT, int n>
inline int myMap<keyT, valueT, n>::Count()
{
	return count;
}

template<typename keyT, typename valueT, int n>
inline bool myMap<keyT, valueT, n>::updateValue(keyT K , valueT V)
{
	bool found = false;
	for (int i = 0; i < count; i++) {
		if (arr[i].getKey() == K) {
			found = true;
			arr[i].setValue(V);
		}
	}
	return found;
 }

template<typename keyT, typename valueT, int n>
inline void myMap<keyT, valueT, n>::displayMap()
{
	for (int i = 0; i < count; ++i) {
		cout << "(" << arr[i].getKey() << " , " << arr[i].getValue() << ")\n";
	}
	cout << "\n";
}

template<typename keyT, typename valueT, int n>
inline void myMap<keyT, valueT, n>::deletePair(mypair<keyT, valueT> somepair)
{
	for (int i = 0; i < count; ++i) {
		if (arr[i] == somepair) {
			arr[i] = arr[count - 1];
			count--;
		}
	}
}

template<typename keyT, typename valueT, int n>
inline mypair<valueT,bool> myMap<keyT, valueT, n>::getValue(keyT K)
{
	mypair<valueT, bool> theValueOrFalse;
	for (int i = 0; i < count; ++i) {
		if (arr[i].getKey() == K) {
			theValueOrFalse.setPair(arr[i].getValue(), true);
			return theValueOrFalse;
		}
	}
	theValueOrFalse.setValue(false);
	return theValueOrFalse;
}
