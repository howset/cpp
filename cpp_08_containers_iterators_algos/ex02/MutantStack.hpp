#pragma once
# include <iostream>
# include <stack>

//std::stack is a container adaptor to std::deque to intentionally hide
//direct access/prevent breaking LIFO, hence no iterators
//inherit from std::stack<T> & gain access to the protected member variable c
// that stores the underlying container
template <typename T>
class MutantStack : public std::stack<T> //must specify type parameter <T> when inheriting from it
{
	public:
		MutantStack(); 
		~MutantStack();
		//MutantStack(MutantStack const &copy);
		MutantStack(const MutantStack<T> &copy);
		MutantStack &operator=(MutantStack const &copy);

		//Iterator typedf & member functs.
		//why typedef like this: ???
		//c is the container from deque
		typedef typename std::stack<T>::container_type::iterator iter;
		iter begin() {return this->c.begin();};
		iter end() {return this->c.end();};

		// typedef typename std::stack<T>::container_type::const_iterator const_iter;
		// const_iter begin() const {return this->c.begin();}
		// const_iter end() const {return this->c.end();}
};

#include "MutantStack.tpp"