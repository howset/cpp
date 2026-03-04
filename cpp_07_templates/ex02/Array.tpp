#pragma once
# include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	//primitive type (int float) are uninitialized --> garbage values (12345 0 0 0)
	//using () to zero initilaize
	//int* a = new int(); //value-initialized to 0
	//std::cout << *a; //output: 0
	//int* b = new int; //uninitialized (garbage)
	//std::cout << *b; //output: random value (e.g., 12345)
	_array = new T[n]();
}

template<typename T>
Array<T>::Array(const Array &src) 
{
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template<typename T>
Array<T>::~Array() 
{
	if (_array)
		delete[] _array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &src) 
{
	if (this == &src) //check for self-assignment
		return (*this);
	if (_array) //if there is something, delete first
		delete[] _array;
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int idx) 
{
	if (idx >= _size)
		throw OORException();
	else
		return (_array[idx]);
}

template<typename T>
unsigned int Array<T>::size() const 
{
	return (_size);
}