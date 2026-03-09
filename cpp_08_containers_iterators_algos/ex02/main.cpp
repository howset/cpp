#include "MutantStack.hpp"
#include <iostream>
#include <list>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

void mutantTest(void);
void listTest(void);
void givenTest(void);

int main()
{
	mutantTest();
	listTest();
	//givenTest();
	return (0);
}

void mutantTest(void)
{
	std::cout << YEL << "mutant stack test" << RES << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	for (MutantStack<int>::iter it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//this time use list and equivalent member functions
void listTest(void)
{
	std::cout << YEL << "list test" << RES << std::endl;
	std::list<int> mstack;
	mstack.push_back(5); //equivalent
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back(); //equivalent
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void givenTest(void)
{
	std::cout << YEL << "given test" << RES << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iter it = mstack.begin();
	MutantStack<int>::iter ite = mstack.end();
	++it;
	//--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); //make an std::stack s obj copy from mstack
}