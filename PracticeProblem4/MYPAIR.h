#pragma once
template <typename keyT , typename valueT = keyT> //if a value type is not specified , default to the key type 
class mypair {
	keyT K;
	valueT V;
public :
	mypair();
	mypair(keyT, valueT);
	void setPair(keyT, valueT);
	void setKey(keyT);
	void setValue(valueT);

	keyT getKey();
	valueT getValue();

	//This might seem weird ,  it is explained in the main why it's necessary
	template<typename keyT,typename valueT,typename differentKeyT,typename differentValueT>
	friend bool operator==(mypair<keyT, valueT> ,
						   mypair<differentKeyT, differentValueT> );
};

template<typename keyT, typename valueT>
inline mypair<keyT, valueT>::mypair()
{
}

template<typename keyT, typename valueT>
inline mypair<keyT, valueT>::mypair(keyT _K, valueT _V){
	K = _K;
	V = _V;
}

template<typename keyT, typename valueT>
inline void mypair<keyT, valueT>::setPair(keyT _K, valueT _V){
	K = _K;
	V = _V;
}

template<typename keyT, typename valueT>
inline void mypair<keyT, valueT>::setKey(keyT x)
{
	K = x;
}

template<typename keyT, typename valueT>
inline void mypair<keyT, valueT>::setValue(valueT x)
{
	V = x;
}

template<typename keyT, typename valueT>
inline keyT mypair<keyT, valueT>::getKey()
{
	return K;
}

template<typename keyT, typename valueT>
inline valueT mypair<keyT, valueT>::getValue()
{
	return V;
}


