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

void PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error: no input provided");
	
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		
		// Check if valid number
		if (arg.empty() || (arg[0] == '-'))
			throw std::runtime_error("Error: invalid input");
		
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
				throw std::runtime_error("Error: invalid input");
		}
		
		long num = std::atol(arg.c_str());
		if (num < 0 || num > 2147483647)
			throw std::runtime_error("Error: number out of range");
		
		_ori.push_back(static_cast<int>(num));
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
	}
}

std::vector<size_t> PmergeMe::generateJS(size_t n)
{
	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	
	size_t i = 2;
	while (jacob[i - 1] < n)
	{
		size_t next = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next);
		i++;
	}
	return jacob;
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
	
	// Generate Jacobsthal sequence
	std::vector<size_t> jacob = generateJS(pending.size());
	
	size_t pos = 1; // Start from second element
	
	for (size_t i = 2; i < jacob.size() && jacob[i] < pending.size(); i++)
	{
		size_t curr = jacob[i];
		size_t prev = jacob[i - 1];
		
		// Insert elements from curr down to prev+1 (reverse order)
		for (size_t j = curr; j > prev && j < pending.size(); j--)
		{
			typename Container::iterator it = 
				std::lower_bound(main.begin(), main.end(), pending[j]);
			main.insert(it, pending[j]);
		}
	}
	
	// Insert any remaining elements
	for (size_t i = pos; i < pending.size(); i++)
	{
		if (std::find(main.begin(), main.end(), pending[i]) == main.end())
		{
			typename Container::iterator it = 
				std::lower_bound(main.begin(), main.end(), pending[i]);
			main.insert(it, pending[i]);
		}
	}
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
	
	// Step 2: Recursively sort main chain
	sortFJ(mainChain);
	
	// Step 3: Insert pending elements using Jacobsthal sequence
	insertLosers(mainChain, pending);
	
	// Step 4: Insert straggler if exists
	if (hasStraggler)
	{
		typename Container::iterator it = 
			std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}
	
	container = mainChain;
}

void PmergeMe::sortNums()
{
	// Sort vector and measure time
	struct timeval start, end;
	gettimeofday(&start, NULL);
	sortFJ(_vec);
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + 
					  (end.tv_usec - start.tv_usec);
	
	// Sort deque and measure time
	gettimeofday(&start, NULL);
	sortFJ(_deq);
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + 
					  (end.tv_usec - start.tv_usec);
	
	// Display results
	std::cout << "Before: ";
	for (size_t i = 0; i < _ori.size() && i < 5; i++)
		std::cout << _ori[i] << " ";
	if (_ori.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size() && i < 5; i++)
		std::cout << _vec[i] << " ";
	if (_vec.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
	
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size() 
			  << " elements with vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() 
			  << " elements with deque  : " << deqTime << " us" << std::endl;
}

void PmergeMe::displayRes() const
{
	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
}

/* // Generate Jacobsthal numbers up to size n
std::vector<int> generateJacobsthal(int n)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	
	while (true)
	{
		int next = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
		if (next > n)
			break;
		jacob.push_back(next);
	}
	return jacob;
}

// Main sorting function
void fordJohnsonSort(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;
	
	// 1. Create pairs and sort them
	std::vector<std::pair<int,int>> pairs;
	bool hasStraggler = false;
	int straggler;
	
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i+1])
			pairs.push_back({arr[i], arr[i+1]});
		else
			pairs.push_back({arr[i+1], arr[i]});
	}
	
	if (arr.size() % 2 != 0)
	{
		hasStraggler = true;
		straggler = arr.back();
	}
	
	// 2. Extract main chain (larger elements)
	std::vector<int> mainChain;
	std::vector<int> pending;
	
	for (auto &p : pairs)
	{
		mainChain.push_back(p.first);
		pending.push_back(p.second);
	}
	
	// 3. Recursively sort main chain
	fordJohnsonSort(mainChain);
	
	// 4. Insert first pending element at the beginning
	mainChain.insert(mainChain.begin(), pending[0]);
	
	// 5. Generate Jacobsthal sequence
	std::vector<int> jacob = generateJacobsthal(pending.size());
	
	// 6. Insert remaining elements in Jacobsthal order
	for (size_t i = 2; i < jacob.size(); i++)
	{
		int idx = jacob[i];
		int prevIdx = jacob[i-1];
		
		// Insert elements between prevIdx and idx in reverse
		for (int j = std::min(idx, (int)pending.size()) - 1; j >= prevIdx; j--)
		{
			// Binary search and insert pending[j]
			auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[j]);
			mainChain.insert(pos, pending[j]);
		}
	}
	
	// 7. Insert straggler if exists
	if (hasStraggler)
	{
		auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}
	
	arr = mainChain;
} */