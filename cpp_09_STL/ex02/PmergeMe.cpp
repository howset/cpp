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

void PmergeMe::parseInput(int argc, char *argv[])
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
		if (num < 0 || num > 2147483647) //negative already handled?
			throw std::runtime_error("Error: out of range");
		_ori.push_back(static_cast<int>(num));
		_vec.push_back(static_cast<int>(num));
		_deq.push_back(static_cast<int>(num));
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

void PmergeMe::sortNums(void)
{
	struct timeval start, end;
	
	_comps = 0;
	gettimeofday(&start, NULL);
	sortVec(_vec);
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	size_t vecComp = _comps;

	_comps = 0;
	gettimeofday(&start, NULL);
	sortDeq(_deq);
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	size_t deqComp = _comps;


	printSeq("Before", _ori, false);
	printSeq("After", _vec, false);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size() 
			  << " elements with vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() 
			  << " elements with deque  : " << deqTime << " us" << std::endl;	
	std::cout << "Vec # of comparisons: " << vecComp << std::endl;
	std::cout << "Deq # of comparisons: " << deqComp << std::endl;
}

void PmergeMe::sortVec(std::vector<int> &_vec)
{
	std::vector<std::pair<int, int> > vecpairs;
	bool hasStraggler = false;
	int straggler = -1;

	//preps
	for (size_t i = 0; i + 1 < _vec.size(); i += 2) //make pairs
		vecpairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	if (_vec.size() % 2 != 0)
	{
		straggler = _vec[_vec.size() - 1];
		hasStraggler = true;
	}

	//arrange/sort/swaps the pair
	for (size_t i = 0; i < vecpairs.size(); i++)
	{
		if (vecpairs[i].first > vecpairs[i].second)
			//vecpairs.push_back(std::make_pair(vecpairs[i].first, vecpairs[i].second));
			std::swap(vecpairs[i].first, vecpairs[i].second);
		_comps++;
	}

	//sort the seq according to the biggest/winner (.second)
	//but this is insertion sort, efficient for small n
	/* for (int i = 1; i < vecpairs.size(); i++)
	{
		std::pair<int, int> toInsert = vecpairs[i];
		int j = i - 1;
		while (j >= 0 && (vecpairs[j].second > toInsert.second))
		{
			vecpairs[j + 1] = vecpairs[j]; //shift the whole unit pair
			j--;
			_comps++;
		}
		vecpairs[j + 1] = toInsert;
	} */

	//this is merge sort, better for more n & the basis for FJ
	if (!vecpairs.empty())
		mergeSortPairs(vecpairs, 0, vecpairs.size() - 1);

	//make mainChain and put the sorted seq in
	std::vector<int> mainChain;
	if (!vecpairs.empty()) //just cautious
		mainChain.push_back(vecpairs[0].first); //vecpairs[0].first is certainly < vecpairs[0].second
	for (size_t i = 0; i < vecpairs.size(); i++)
		mainChain.push_back(vecpairs[i].second); //put the big numbers

	std::vector<int> pendChain; // pending elements to insert
	for (size_t i = 1; i < vecpairs.size(); i++)
		pendChain.push_back(vecpairs[i].first);
	std::vector<size_t> jacobsthal = genJS(pendChain.size());

	// Insert in Jacobsthal order
	for (size_t i = 0; i < jacobsthal.size(); i++)
	{
		size_t idx = jacobsthal[i];
		if (idx < pendChain.size())
		{
			int toInsert = pendChain[idx];
			insertBinary(mainChain, toInsert); //binary search for insertion position
		}
	}
	if (hasStraggler) //finally the straggler
		insertBinary(mainChain, straggler);

	// Copy mainChain back to _vec
	_vec = mainChain;
}

void PmergeMe::sortDeq(std::deque<int> &_deq)
{
	(void) _deq;
}

void PmergeMe::mergeSortPairs(std::vector<std::pair<int, int> > &pairs, int l_idx, int r_idx)
{
	if (l_idx >= r_idx) //basecase (0 / 1 elemnt)
		return;
	int mid_idx = l_idx + (r_idx - l_idx) / 2;
	mergeSortPairs(pairs, l_idx, mid_idx); //recursion sort left half
	mergeSortPairs(pairs, mid_idx + 1, r_idx); //recursion sort right half
	mergePairs(pairs, l_idx, mid_idx, r_idx); //merge every sorted halves
}

void PmergeMe::mergePairs(std::vector<std::pair<int, int> > &pairs, int l_idx, int mid_idx, int r_idx)
{
	std::vector<std::pair<int, int> > l_half(pairs.begin() + l_idx, pairs.begin() + mid_idx + 1); //temp vec seq for left half
	std::vector<std::pair<int, int> > r_half(pairs.begin() + mid_idx + 1, pairs.begin() + r_idx + 1); //temp vec seq for right half
	size_t i = 0, j = 0, k = l_idx;
	while (i < l_half.size() && j < r_half.size()) //merge the two halves back into pairs
	{
		_comps++;
		if (l_half[i].second <= r_half[j].second)
		{
			pairs[k] = l_half[i];
			i++;
		}
		else
		{
			pairs[k] = r_half[j];
			j++;
		}
		k++;
	}
	while (i < l_half.size()) //copy remaining elements from left half
	{
		pairs[k] = l_half[i];
		i++;
		k++;
	}
	while (j < r_half.size()) //copy remaining elements from right half
	{
		pairs[k] = r_half[j];
		j++;
		k++;
	}
}

std::vector<size_t> PmergeMe::genJS(size_t n)
{
	std::vector<size_t> jreturn;
	if (n == 0) 
		return jreturn;
	std::vector<size_t> jseq;
	jseq.push_back(0);
	jseq.push_back(1);
	while (jseq.back() < n) //generate j sequence
	{
		size_t next = jseq[jseq.size() - 1] + 
					  2 * jseq[jseq.size() - 2];
		jseq.push_back(next);
	}
	for (size_t i = 2; i < jseq.size(); i++) //build insertion order after j seq is generated
	{
		size_t curr = jseq[i];
		size_t prev = jseq[i - 1];
		for (size_t j = std::min(curr, n); j > prev; j--) // Insert from curr down to prev+1
			jreturn.push_back(j - 1); // Convert to 0-indexed
	}
	return (jreturn);
}

void PmergeMe::insertBinary(std::vector<int> &chain, int value)
{
	int l_idx = 0;
	int r_idx = chain.size();
	while (l_idx < r_idx)
	{
		int mid_idx = l_idx + (r_idx - l_idx) / 2; //(l + r)/2 might overflow
		_comps++;
		if (chain[mid_idx] < value)
			l_idx = mid_idx + 1;
		else
			r_idx = mid_idx;
	}
	chain.insert(chain.begin() + l_idx, value); //insert at position left
}