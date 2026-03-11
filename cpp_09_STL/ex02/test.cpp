#include "PmergeMe.hpp"

void PmergeMe::runTest()
{
	std::srand(std::time(NULL)); //randomize seed
	for (int n = 5; n <= 30; n += 5)
	{
		std::cout << YEL << "\nn = " << n << RES << std::endl;
		_ori.clear();
		_vec.clear();
		_deq.clear();
		for (int i = 0; i < n; i++)
		{
			int num = std::rand() % 50; //randomize number 0-49
			_ori.push_back(num);
			_vec.push_back(num);
			_deq.push_back(num);
		}
		sortNums();
	}
}