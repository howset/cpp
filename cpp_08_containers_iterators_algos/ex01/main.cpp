#include "Span.hpp"
#include <iostream>
#include <cstdlib> //rand()
#include <ctime> //time()

void testMany(void);

int main (void)
{
	Span sp(5);
	
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(-9);
		sp.addNumber(11);
		//sp.addNumber(13); //full
		int longest = sp.longestSpan();
		std::cout << "Longest span: " << longest << std::endl;
		int shortest = sp.shortestSpan();
		std::cout << "Shortest span: " << shortest << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	sp.printContent();
	
	testMany();
	return (0);
}

void testMany(void)
{
	//srand(time(NULL));
	Span sp(10000);
	try
	{
		for (int i = 0; i < 10000; i++)
			sp.addNumber(rand() % 100000); //random numbers 0-99999
		int shortest = sp.shortestSpan();
		std::cout << "Shortest span: " << shortest << std::endl;
		int longest = sp.longestSpan();
		std::cout << "Longest span: " << longest << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}