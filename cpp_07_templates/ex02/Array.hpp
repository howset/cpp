#pragma once
# include <iostream>

template <typename T>
class Array{
	private:
		T				*_array; //can be anything (int str)
		unsigned int 	_size;

	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &src);

		Array& operator=(const Array &src);
		T& operator[](unsigned int idx);
		
		unsigned int size() const;

	class IndexOutOfRangeException : public std::exception{
		public:
			virtual const char *what() const throw()
			{
				return ("Out of range");
			}
	};
};

#include "Array.tpp" 