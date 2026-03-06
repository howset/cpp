#pragma once
# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

//directly calls the base class copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy) {}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator= (MutantStack const &copy)
{
	if (this == &copy) //check for self-assignment
		return (*this);
	std::stack<T>::operator=(copy);
	return (*this);
}
