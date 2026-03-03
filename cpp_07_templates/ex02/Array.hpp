#pragma once
# include <iostream>

template <typename T> class Array{
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array &src);

		Array& operator=(const Array &src);
		T& operator[](unsigned int index);
		
		unsigned int size() const;

	private:
		T* 				_array;
		unsigned int 	_size;

	class IndexOutOfRangeException : public std::exception{
		public:
			virtual const char* what() const throw()
			{
				return ("Out of range");
			}
	};
};