#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <sys/time.h> //gettimeofday
# include <ctime> //std::time
# include <iomanip> //setprecision
# include <algorithm> //atoi
# include <cmath> //log2

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

class PmergeMe
{
private:
	std::vector<int> _ori;
	std::vector<int> _vec;
	std::deque<int> _deq;
	size_t _comps;
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);

	void parseArgs(int argc, char *argv[]);
	void sortNums(void);
	std::vector<size_t> generateJacobsthal(size_t n);
	std::vector<size_t> buildInsertionOrder(size_t size);
	void runTest(void);
	
	template <typename Container>
		void sortFJ(Container &container);
	template <typename Container>
		void insertPending(Container &main, const Container &pending);
	template <typename Container>
		void printSeq(std::string when, Container &cont, bool trunc);
};

template <typename Container>
void PmergeMe::sortFJ(Container &container)
{
	if (container.size() <= 1)
		return;
	Container mainChain;
	Container pendChain;
	bool hasStraggler = false;
	int straggler = 0;
	size_t i = 0;
	while (i + 1 < container.size())
	{
		_comps++;
		if (container[i] > container[i + 1])
		{
			mainChain.push_back(container[i]);
			pendChain.push_back(container[i + 1]);
		}
		else
		{
			mainChain.push_back(container[i + 1]);
			pendChain.push_back(container[i]);
		}
		i += 2;
	}
	if (i < container.size()) //odd element
	{
		hasStraggler = true;
		straggler = container[i];
	}
	// Step 2: Recursively sort mainChain (winners)
	sortFJ(mainChain);
	
	// Step 3: Insert pending elements using Jacobsthal sequence
	insertPending(mainChain, pendChain);
	
	// Step 4: Insert straggler if exists
	if (hasStraggler)
	{
		size_t left = 0, right = mainChain.size();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			_comps++;
			if (mainChain[mid] < straggler)
				left = mid + 1;
			else
				right = mid;
		}
		typename Container::iterator it = mainChain.begin() + left;
		mainChain.insert(it, straggler);
	}
	
	container = mainChain;
}

template <typename Container>
void PmergeMe::insertPending(Container &main, const Container &pending)
{
	if (pending.empty())
		return;
	// Insert first pending element at beginning
	main.insert(main.begin(), pending[0]);
	if (pending.size() == 1)
		return;
	// Generate Jacobsthal sequence
	std::vector<size_t> insertionOrder = buildInsertionOrder(pending.size());
	// Insert remaining elements in Jacobsthal order
	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		size_t idx = insertionOrder[i];
		if (idx <= 0 || idx >= pending.size())
			continue;
		int val = pending[idx];
		// Manual binary search to count comparisons
		size_t left = 0, right = main.size();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			_comps++;
			if (main[mid] < val)
				left = mid + 1;
			else
				right = mid;
		}
		typename Container::iterator it = main.begin() + left;
		main.insert(it, val);
	}
}

template <typename Container>
void PmergeMe::printSeq(std::string when, Container &cont, bool trunc)
{
	std::cout << when << ": ";
	if (trunc)
	{
		for (size_t i = 0; i < cont.size() && i < 5; i++)
			std::cout << cont[i] << " ";
		std::cout << "[...]";
	}
	else
	{
		for (size_t i = 0; i < cont.size(); i++)
			std::cout << cont[i] << " ";
	}
	std::cout << std::endl;
}