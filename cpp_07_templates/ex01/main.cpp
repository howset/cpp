#include "iter.hpp"

int main( void ) {
	// int arr[] = {5, 2, 8, 1, 9};
	// int len = 5;
	// double arr[] = {3.14, 1.23, 5.67, 0.99};
	// int len = 4;
	char arr[] = {'z', 'a', 'm', 'b', 'c'};
	int len = 5;

	std::cout << "Print: " << std::endl;
	iter(arr, len, printArr);
	std::cout << std::endl;
	std::cout << "Sort: " << std::endl;
	sortArr(arr, len);
	iter(arr, len, printArr);
	std::cout << std::endl;
	std::cout << "Increment: " << std::endl;
	iter(arr, len, incrArr);
	iter(arr, len, printArr);
	std::cout << std::endl;
	return 0;
}