#pragma once
#include<ostream>
#include<iostream>
using namespace std;
template<class type>
class Dictionary
{
	type key;
	int count;
public:
	Dictionary() :count(0) {}
	Dictionary(type k) :count(0), key(k) {}
	Dictionary(type k, int c) :count(c), key(k) {}
	void setCount(int c) { count = c; }
	void setKey(type k) { key = k; }
	int getCount() const { return count; }
	type getKey() const { return key; }
	friend ostream& operator<<(ostream& print, const Dictionary& Dict)
	{
		print << "{" << Dict.getKey() << "," << Dict.getCount() << "}";
		return print;
	}
};

