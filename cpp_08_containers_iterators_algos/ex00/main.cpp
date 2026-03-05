#include "easyfind.hpp"
#include <vector> //dynamic array, fast random access
#include <list> //doubly-linked list, fast insertion/deletion

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

int main (void)
{
	std::cout << YEL << "Vector container" << RES << std::endl;
	std::vector<int> vect;
	for (size_t i = 0; i < 10; i++)
		vect.push_back(i);
	std::cout << "contents: ";
	for (unsigned int i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
	try 
	{
		int n = 4; //change
		std::vector<int>::iterator it = easyfind(vect, n);
		std::cout << "value: " << n << " at position: " << std::distance(vect.begin(), it) << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << YEL << "List container" << RES << std::endl;
	std::list<int> dll;
	for (size_t i = 0; i < 10; i++)
		dll.push_back(i);
	std::cout << "contents: ";
	for (std::list<int>::const_iterator it = dll.begin(); it != dll.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	try 
	{
		int n = 5; //change
		std::list<int>::iterator it = easyfind(dll, n);
		std::cout << "Found value " << n << " at position: " << std::distance(dll.begin(), it) << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}