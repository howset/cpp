#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	try
	{
		PmergeMe sorter;
		sorter.parseInput(argc, argv);
		if (std::string(argv[1]) != "test")
			sorter.sortNums();
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
		return (1);
	}
	return (0);
}