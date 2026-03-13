#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) : _ori(copy._ori), _vec(copy._vec), _deq(copy._deq), _comps(copy._comps){}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_ori = copy._ori;
		_vec = copy._vec;
		_deq = copy._deq;
		_comps = copy._comps;
	}
	return (*this);
}

void PmergeMe::parseArgs(int argc, char *argv[])
{
	if (argc == 2 && std::string(argv[1]) == "test")
	{
		runTest();
		return;
	}
	else if (argc < 2)
		throw std::runtime_error("Error: insufficient input");
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (arg.empty() || (arg[0] == '-'))
			throw std::runtime_error("Error: empty/negative input");
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
				throw std::runtime_error("Error: nondigit input");
		}
		int num = std::atoi(arg.c_str());
		if (num > 2147483647)
			throw std::runtime_error("Error: out of range");
		_ori.push_back(static_cast<int>(num));
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
}

void PmergeMe::sortNums(void)
{
	struct timeval start, end;

	_comps = 0;
	gettimeofday(&start, NULL);
	sortFJ(_vec, false); //true for debug
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	size_t vecComp = _comps;

	_comps = 0;
	gettimeofday(&start, NULL);
	sortFJ(_deq, false);
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	size_t deqComp = _comps;

	printSeq("Before", _ori, false); //true for truncation
	printSeq("After", _vec, false);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with deque  : " << deqTime << " us" << std::endl;
	std::cout << "Vec # of comparisons: " << vecComp << std::endl;
	std::cout << "Deq # of comparisons: " << deqComp << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> jacob;
	size_t j0 = 3;
	size_t j1 = 5;

	if (n > 1) jacob.push_back(j0);
	if (n > 3) jacob.push_back(j1);

	while (true)
	{
		size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= n + 2)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

std::vector<size_t> PmergeMe::buildInsertionOrder(size_t size)
{
	std::vector<size_t> order;
	if (size <= 1)
		return order;
	std::vector<size_t> jacob = generateJacobsthal(size);
	size_t lastLimit = 0;
	for (size_t i = 0; i < jacob.size(); i++)
	{
		size_t upperLimit = (jacob[i] >= size) ? size - 1 : jacob[i];
		for (size_t j = upperLimit; j > lastLimit; j--) // Insert in descending order
			order.push_back(j);
		if (upperLimit > lastLimit)
			lastLimit = upperLimit;
		if (upperLimit >= size - 1)
			break;
	}
	// FIX: Add any remaining elements that weren't covered by Jacobsthal sequence
	if (lastLimit < size - 1)
	{
		for (size_t j = size - 1; j > lastLimit; j--)
			order.push_back(j);
	}
	return order;
}