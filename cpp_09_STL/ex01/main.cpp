#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("Error: wrong arguments");
		RPN calc;
		int res = calc.evaluate(argv[1]);
		std::cout << res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RES << std::endl;
		return (1);
	}
	return (0);
}