#pragma once

# include <algorithm> //std::find

//works with any container that has iterators
template<typename T> 
typename T::iterator easyfind(T &cont, int n)
{
	typename T::iterator iter_res = std::find(cont.begin(), cont.end(), n);
	if (iter_res == cont.end())
		throw MatchNotFoundException();
	return (iter_res);
}