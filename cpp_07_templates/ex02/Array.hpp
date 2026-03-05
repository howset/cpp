#pragma once
# include <iostream>

template <typename T>
class Array{
	private:
		T				*_array; //can be anything (int str)
		unsigned int 	_size;

	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &src);

		Array &operator=(const Array &src);
		T &operator[](unsigned int idx);
		//const T &operator[](unsigned int idx) const {
		// 	if (idx >= _size)
		// 		throw OORException();
		// 	return (_array[idx]);
		// };
		
		unsigned int size() const;

	class OORException : public std::exception{
		public:
			virtual const char *what() const throw()
			{
				return ("Out of range");
			}
	};
};

#include "Array.tpp" 