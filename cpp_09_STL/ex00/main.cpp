#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc = 2)
	{
		BitcoinExchange btc;
		btc.loadData("data.csv");
		btc.processInput(argv[1]);
		return (0);
	}
	std::cerr << "Retry." << std::endl;
	return (1);
}