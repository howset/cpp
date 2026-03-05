#pragma once
#include <vector>
#include <iterator>

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

		template <typename InputIterator>
		void	addRange(InputIterator begin, InputIterator end)
		{
			size_t count = std::distance(begin, end);
			if (_content.size() + count > _length)
				throw ContentFullException();
			_content.insert(_content.end(), begin, end);
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