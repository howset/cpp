#include <iostream> //already includes ostream: cout, endl
#include <cctype> //toupper

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)(std::toupper(argv[i][j]));
			if (i < argc - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
		return (0);
	}
}