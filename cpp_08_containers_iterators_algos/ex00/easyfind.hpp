#pragma once

# include <iostream>
# include <exception> //std::exception

class MatchNotFoundException : public std::exception{
	public:
		virtual const char *what() const throw()
		{
			return ("Match not found.");
		}
};

template<typename T> 
typename T::iterator easyfind(T &cont, int n);

#include "easyfind.tpp"
