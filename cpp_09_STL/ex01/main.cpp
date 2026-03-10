#include "RPN.hpp"

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

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