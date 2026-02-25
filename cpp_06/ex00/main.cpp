#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::string arg = argv[1];
		ScalarConverter::convert(arg);
	}
	else
		std::cerr << "2 args only : ./convert and a char, float, int or double" << std::endl; 
}