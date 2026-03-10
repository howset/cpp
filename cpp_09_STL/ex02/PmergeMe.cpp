#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) :  _ori(copy._ori), _vec(copy._vec), _deq(copy._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		_ori = copy._ori;
		_vec = copy._vec;
		_deq = copy._deq;
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
		size_t next = jseq[i - 1] + 2 * jseq[i - 2];
		jseq.push_back(next);
		i++;
	}
	return (jseq);
}

template <typename Container>
void PmergeMe::sortFJ(Container &container)
{
	if (container.size() <= 1)
		return;
	// Step 1: Create pairs and sort them
	Container mainChain;
	Container pending;
	bool hasStraggler = false;
	typename Container::value_type straggler;
	size_t i = 0;
	while (i + 1 < container.size())
	{
		if (container[i] > container[i + 1])
		{
			mainChain.push_back(container[i]);
			pending.push_back(container[i + 1]);
		}
		else
		{
			mainChain.push_back(container[i + 1]);
			pending.push_back(container[i]);
		}
		i += 2;
	}
	// Handle odd element
	if (i < container.size())
	{
		hasStraggler = true;
		straggler = container[i];
	}
	sortFJ(mainChain); // Step 2: Recursively sort main chain
	insertLosers(mainChain, pending); // Step 3: Insert pending elements using Jacobsthal sequence
	if (hasStraggler) // Step 4: Insert straggler if exists
	{
		typename Container::iterator it = 
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	container = mainChain;
}

template <typename Container>
void PmergeMe::insertLosers(Container &main, const Container &pending)
{
	if (pending.empty())
		return;
	// Insert first pending element at beginning
	main.insert(main.begin(), pending[0]);
	if (pending.size() == 1)
		return;
	std::vector<size_t> jacob = generateJS(pending.size()); //generate jacobsthal seq
	size_t pos = 1; //start from second element
	for (size_t i = 2; i < jacob.size() && jacob[i] < pending.size(); i++)
	{
		size_t curr = jacob[i];
		size_t prev = jacob[i - 1];
		for (size_t j = curr; j > prev && j < pending.size(); j--) //insert elements from curr down to prev+1 (reverse order)
		{
			typename Container::iterator it = 
				std::lower_bound(main.begin(), main.end(), pending[j]);
			main.insert(it, pending[j]);
		}
	}
	for (size_t i = pos; i < pending.size(); i++) //insert remaining elements
	{
		if (std::find(main.begin(), main.end(), pending[i]) == main.end())
		{
			typename Container::iterator it = 
				std::lower_bound(main.begin(), main.end(), pending[i]);
			main.insert(it, pending[i]);
		}
	}
}

void PmergeMe::sortNums()
{
	
	struct timeval start, end;
	gettimeofday(&start, NULL);
	sortFJ(_vec); // Sort vector and measure time
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	sortFJ(_deq); // Sort deque and measure time
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 +  (end.tv_usec - start.tv_usec);
	
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
}