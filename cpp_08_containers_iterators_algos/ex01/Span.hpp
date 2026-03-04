#pragma once
#include <vector>

class Span
{
	private:
		unsigned int		_length;
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