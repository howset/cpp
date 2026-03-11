#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) :  _ori(copy._ori), _vec(copy._vec), _deq(copy._deq), _comparisons(copy._comparisons){}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_ori = copy._ori;
		_vec = copy._vec;
		_deq = copy._deq;
		_comparisons = copy._comparisons;
	}
	return (*this);
}

void PmergeMe::parseInput(int argc, char *argv[])
{
	if (argc < 2)
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
		if (num < 0 || num > 2147483647) //negative already handled?
			throw std::runtime_error("Error: out of range");
		_ori.push_back(static_cast<int>(num));
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
}

std::vector<size_t> PmergeMe::generateJS(size_t n)
{
	std::vector<size_t> jseq;
	jseq.push_back(0);
	jseq.push_back(1);
	size_t i = 2;
	while (jseq[i - 1] < n)
	{
		size_t next = jseq[i - 1] + 2 * jseq[i - 2]; //J_n=J_(n−1)+2J_(n−2)
		jseq.push_back(next);
		i++;
	}
	return (jseq);
}

void PmergeMe::sortNums()
{
	
	struct timeval start, end;

	_comparisons = 0;
	gettimeofday(&start, NULL);
	sortFJ(_vec); // Sort vector and measure time
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	size_t vecComp = _comparisons;
	
	_comparisons = 0;
	gettimeofday(&start, NULL);
	sortFJ(_deq); // Sort deque and measure time
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 +  (end.tv_usec - start.tv_usec);
	size_t deqComp = _comparisons;

	// Display results
	std::cout << "Before: ";
	for (size_t i = 0; i < _ori.size(); i++)
	//for (size_t i = 0; i < _ori.size() && i < 5; i++)
		std::cout << _ori[i] << " ";
	//if (_ori.size() > 5)
	//	std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); i++)
	//for (size_t i = 0; i < _vec.size() && i < 5; i++)
		std::cout << _vec[i] << " ";
	//if (_vec.size() > 5)
	//	std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size() 
			  << " elements with vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() 
			  << " elements with deque  : " << deqTime << " us" << std::endl;
	
	std::cout << "Vec comparisons: " << vecComp << std::endl;
	std::cout << "Deq comparisons: " << deqComp << std::endl;
}