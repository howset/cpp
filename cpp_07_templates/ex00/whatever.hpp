#pragma once

//The basic idea is passing the data type as a parameter so that it is not 
//necessary to write the same code for different data types. 
//E.g. usign a sort() func for different data types. 
// Template definitions need to be in header
template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T>
T min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}
