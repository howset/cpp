#pragma once
# include <iostream>


template<typename T> 
typename T::iterator easyfind(T &cont, int n);
class MatchNotFoundException : public std::exception{
	public:
		virtual const char *what() const throw()
		{
			return ("Match not found.");
		}
};

#include "easyfind.tpp"
