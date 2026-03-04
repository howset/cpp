#include "Span.hpp"
#include <iostream>
#include <algorithm> //min max

Span::Span() : _length(0) {}

Span::Span(unsigned int n) : _length(n) {}

Span::~Span() {}

Span::Span(Span const &copy) 
{
	*this = copy;
}

Span &Span::operator=(Span const &copy)
{
	if (this != &copy)
	{
		_length = copy._length;
		_content = copy._content;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_content.size() >= _length)
		throw ContentFullException(); 
	_content.push_back(n);
}

int Span::shortestSpan()
{
	if (_content.size() < 2)
		throw NotPossibleException();
	std::vector<int> _sorted = _content;
	std::sort(_sorted.begin(), _sorted.end());
	int min = _sorted[1] - _sorted[0];
	for (unsigned long i = 0; i < _sorted.size() - 1; i++)
	{
		int next = _sorted[i + 1] - _sorted[i];
		if (next < min)
			min = next;
	}
	return (min);
}

int Span::longestSpan()
{
	if (_content.size() < 2)
		throw NotPossibleException();
	int min = *std::min_element(_content.begin(), _content.end());
	int max = *std::max_element(_content.begin(), _content.end());
	return (max - min);
}

void Span::printContent() const
{
	std::cout << "Span contents: ";
	for (std::vector<int>::const_iterator it = _content.begin(); it != _content.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}