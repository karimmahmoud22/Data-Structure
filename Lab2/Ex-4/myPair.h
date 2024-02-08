#pragma once
template <class K,class V>
class myPair
{
private:
	K Key;
	V Value;
public:
	myPair(K k, V v)
	{
		setPair(k, v);
	}
	myPair()
	{

	}
	void setPair(K k, V v)
	{
		Key = k;
		Value = v;
	}
	K getKey()
	{
		return Key;
	}
	V getValue()
	{
		return Value;
	}
	bool operator == (myPair P)
	{
		return (Key == P.Key && Value = P.Value);
	}
	~myPair()
	{

	}
};

