#include <iostream>

int main(int argc, char *argv[])
{
	char	**str;

	if (argc == 1)
	{
		std :: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std :: endl;
		return (1);
	}
	str = &argv[1];
	for (int i = 0; str[i]; i++)
	{
		for (int j = 0; str[i][j]; j++)
			std :: cout << (char)(std::toupper(str[i][j]));
	}
	std :: cout << std :: endl;
	return (0);
}