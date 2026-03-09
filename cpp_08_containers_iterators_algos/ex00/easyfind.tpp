#pragma once

# include <algorithm> //std::find

//works with any container that has iterators
//T itself is a container of integers
//finds the first occurence (if there are duplicates)
template<typename T> 
typename T::iterator easyfind(T &cont, int n)
{
	typename T::iterator idx_res = std::find(cont.begin(), cont.end(), n);
	if (idx_res == cont.end())
		throw MatchNotFoundException();
	return (idx_res);
}