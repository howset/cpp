#pragma once
#include <vector>
#include <iostream>

class Span
{
	private:
		unsigned int		_length; //may not exceed this maximum
		std::vector<int>	_content;
	public:
		Span();
		Span(unsigned int n); 
		~Span();
		Span(Span const &copy);
		Span &operator=(Span const &copy);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	printContent() const;
		
		//template definition has to be in header
		template <typename Range>
		void	addRange(Range begin, Range end)
		{
			size_t dist = std::distance(begin, end); //count elements
			if (_content.size() + dist > _length)
				throw ContentFullException();
			_content.insert(_content.end(), begin, end); //append the elemetns
		}
		class ContentFullException : public std::exception 
		{
			public:
				virtual const char* what() const throw() 
				{
					return "Content full";
				}
		};

		class NotPossibleException : public std::exception 
		{
			public:
				virtual const char* what() const throw() 
				{
					return "Not enough elements";
				}
		};
};