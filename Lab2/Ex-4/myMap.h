#pragma once
#include "myPair.h"
#include <iostream>
using namespace std;

template <class K, class V, int Size = 100>
class myMap
{
private:
	myPair <K, V>* pairList;
	int Count;
public:
	myMap()
	{
		pairList = new myPair<K, V>[Size];
		Count = 0;
	}
	bool addPair(myPair<K, V> P)
	{
		if (Count < Size)
		{
			pairList[Count++] = P;
			return true;
		}
		return false;
	}
	bool getValue(K k, V& value)
	{
		for (int i = 0; i < Count; i++)
		{
			if (pairList[i].getKey() == k)
			{
				value = pairList[i].getValue();
					return true;
			}
		}
		return false;
	}
	int count()
	{
		return Count;
	}
	bool updateValue(K k, V value)
	{
		for (int i = 0; i < Count; i++)
		{
			if (pairList[i].getKey() == k)
			{
				pairList[i].setPair(k, value);
				return true;
			}
		}
		return false;
	}
	void displayMap()
	{
		for (int i = 0; i < Count; i++)
		{
			cout << "(" << pairList[i].getKey() << ",";
			cout << pairList[i].getValue() << ")";
			cout << " ";
		}
		cout << endl;
	}
	bool deletePair(myPair<K, V> P)
	{
		for (int i = 0; i < Count; i++)
		{
			if (pairList[i].getKey() == P.getKey() &&
				pairList[i].getValue() == P.getValue())
			{
				pairList[i] = pairList[Count - 1];
				Count--;
				return true;
			
			}
		}
		return false;
	}
	~myMap()
	{
		delete[] pairList;
	}
};

