#include "Span.hpp"
#include <iostream>
#include <cstdlib> //rand()
#include <ctime> //time()

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

void testSmall(void);
void testBig(void);
void testRange(void);

int main (void)
{
	testSmall();
	testBig();
	testRange();
	return (0);
}

void testSmall(void)
{
	std::cout << YEL << "small test" << RES << std::endl;
	Span sp(5);
	//sp.printContent();
	try
	{
		sp.addNumber(6);
		//sp.printContent();
		sp.addNumber(3);
		//sp.printContent();
		sp.addNumber(17);
		//sp.printContent();
		sp.addNumber(-9);
		//sp.printContent();
		sp.addNumber(11);
		//sp.printContent();
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
}
void testBig(void)
{
	std::cout << YEL << "big test" << RES << std::endl;
	//srand(time(NULL)); //randomize eveytime
	//srand(666);
	int n = 10000;
	Span sp(n);
	try
	{
		for (int i = 0; i < n; i++)
			sp.addNumber(rand() % 10000); //random numbers 0-99999
		int shortest = sp.shortestSpan();
		std::cout << "Shortest span: " << shortest << std::endl;
		int longest = sp.longestSpan();
		std::cout << "Longest span: " << longest << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	//sp.printContent();
}

//how is this less annoying?
void testRange(void)
{
	std::cout << YEL << "range test" << RES << std::endl;
	//srand(time(NULL)); //randomize eveytime
	//srand(666);
	int n = 10000;
	Span sp(n);
	try
	{
		std::vector<int> numbers;
		for (int i = 0; i < n; i++)
			numbers.push_back(rand() % 10000); //random numbers 0-99999
		sp.addRange(numbers.begin(), numbers.end());
		int shortest = sp.shortestSpan();
		std::cout << "Shortest span: " << shortest << std::endl;
		int longest = sp.longestSpan();
		std::cout << "Longest span: " << longest << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	//sp.printContent();
}