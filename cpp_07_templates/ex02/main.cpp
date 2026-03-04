#include <iostream>
#include <cstdlib>//rand, srand
#include <ctime>//time
#include "Array.hpp"

#define MAX_VAL 750
#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

void selftest();
int giventest();

int main (void)
{
	selftest();
	//giventest();
	return (0);
}

void selftest(void)
{
	std::cout << YEL << "default constructor" << RES << std::endl;
	Array<int> empty;
	std::cout << "Size of empty array: " << empty.size() << std::endl;
	
	std::cout << YEL << "parameterize constructor" << RES << std::endl;
	Array<int> arr(5);
	std::cout << "Size of arr: " << arr.size() << std::endl;
	std::cout << YEL << "accessing elements" << RES << std::endl;
	std::cout << "Array contents: ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << YEL << "modifying elements" << RES << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;
	std::cout << "Array contents: ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
	std::cout << std::endl;
	
	std::cout << YEL << "copy constructor" << RES << std::endl;
	Array<int> copy(arr);
	std::cout << "original arr: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "copy: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;
	std::cout << YEL << "   deep copy" << RES << std::endl;
	copy[0] = 999;
	std::cout << "original arr[0]: " << arr[0] << std::endl;
	std::cout << "copy[0]: " << copy[0] << std::endl;

	std::cout << YEL << "assignment operator" << RES << std::endl;
	Array<int> assigned;
	assigned = arr;
	std::cout << "original arr: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "assigned: ";
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;
	std::cout << YEL << "   deep copy" << RES << std::endl;
	assigned[1] = 99999;
	std::cout << "original arr[1]: " << arr[1] << std::endl;
	std::cout << "assigned[1]: " << assigned[1] << std::endl;

	std::cout << YEL << "exceptions - assigning val to invalid idx" << RES << std::endl;
	try 
	{
		arr[10] = 42;
	}
	catch (std::exception& e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YEL << "exceptions - accessing empty arr" << RES << std::endl;
	try 
	{
		empty[0] = 5;
	}
	catch (std::exception& e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << YEL << "test other types" << RES << std::endl;
	Array<std::string> strArr(2);
	strArr[0] = "Aha";
	strArr[1] = "!";
	std::cout << "strArr: ";
	for (unsigned int i = 0; i < strArr.size(); i++)
	    std::cout << strArr[i] << " ";
	std::cout << std::endl;

	Array<double> dblArr(2);
	dblArr[0] = 3.14;
	dblArr[1] = 2.71;
	std::cout << "dblArr: ";
	for (unsigned int i = 0; i < dblArr.size(); i++)
	    std::cout << dblArr[i] << " ";
	std::cout << std::endl;

	std::cout << YEL << "chain assigning" << RES << std::endl;
	Array<int> a(2);
	Array<int> b(2);
	Array<int> c(2);
	a[0] = 10;
	a[1] = 20;
	c = b = a;
	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
	    std::cout << a[i] << " ";
	std::cout << std::endl;
	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
	    std::cout << b[i] << " ";
	std::cout << std::endl;
	std::cout << "c: ";
	for (unsigned int i = 0; i < c.size(); i++)
	    std::cout << c[i] << " ";
	std::cout << std::endl;
}

int giventest(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}