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

struct Pairing
{
	int smaller;
	int bigger;
	size_t bound_pos;
	Pairing(int s, int b, size_t bp) : smaller(s), bigger(b), bound_pos(bp) {}
};

class PmergeMe
{
private:
	std::vector<int> _ori;
	std::vector<int> _vec;
	std::deque<int> _deq;
	size_t _co;
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
		void sortFJ(Container &container, bool debug = false);
	template <typename Container>
		void printSeq(std::string when, Container &cont, bool trunc);
};

template <typename Container>
void PmergeMe::sortFJ(Container &container, bool debug)
{
	if (container.size() <= 1)
		return;
	if (debug) 
	{
		std::cout << BLU << "seq size: " << container.size() << RES << std::endl;
		std::cout << BLU << "seq: [";
		for (size_t i = 0; i < container.size(); i++)
		{
			std::cout << container[i];
			if (i < container.size() - 1) std::cout << ", ";
		}
		std::cout << "]" << RES << std::endl;
	}
	bool oddseq = container.size() % 2 != 0; //handle odd element
	int strag = 0;
	if (oddseq)
	{
		strag = container.back();
		container.pop_back();
		if (debug) std::cout << BLU << "Odd el (stragg): " << strag << RES << std::endl;
	}
	std::vector<Pairing> pairings;
	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		_co++;
		int a = container[i], b = container[i+1];
		if (a < b)
			std::swap(a, b);
		pairings.push_back(Pairing(b, a, 0));
	}
	if (debug) 
	{
		std::cout << YEL << "I: make pair & rearrange" << RES << std::endl;
		std::cout << YEL << "pairs: " << pairings.size() << RES << std::endl;
		for (size_t i = 0; i < pairings.size(); i++)
		{
			std::cout << YEL << "  pair[" << i << "] = (smaller: " << pairings[i].smaller 
				<< ", bigger: " << pairings[i].bigger << ")" << RES << std::endl;
		}
	}
	Container bigger;
	for (size_t i = 0; i < pairings.size(); i++)
		bigger.push_back(pairings[i].bigger);
	if (debug) 
	{
		std::cout << YEL << "II: sort bigger chain recursive" << RES << std::endl;
		std::cout << YEL << "bigger chain (" << bigger.size() << " els): [";
		for (size_t i = 0; i < bigger.size(); i++)
		{
			std::cout << bigger[i];
			if (i < bigger.size() - 1) std::cout << ", ";
		}
		std::cout << "]" << RES << std::endl;
		std::cout << YEL << "recursive sortFJ call..." << RES << std::endl;
	}
	sortFJ(bigger, debug);
	if (debug) 
	{
		std::cout << CYA << "back from recursion. Sorted 'bigger' chain: [";
		for (size_t i = 0; i < bigger.size(); i++)
		{
			std::cout << bigger[i];
			if (i < bigger.size() - 1) std::cout << ", ";
		}
		std::cout << "]" << RES << std::endl;
	}
	std::vector<bool> used(pairings.size(), false);
	std::vector<Pairing> reordered;
	for (size_t i = 0; i < bigger.size(); i++)
	{
		for (size_t j = 0; j < pairings.size(); j++)
		{
			if (!used[j] && pairings[j].bigger == bigger[i])
			{
				reordered.push_back(pairings[j]);
				used[j] = true;
				break;
			}
		}
	}
	if (debug) 
	{
		std::cout << YEL << "III: rematch pairings - build chains" << RES << std::endl;
		std::cout << YEL << "rematched to bigger chain:" << RES << std::endl;
		for (size_t i = 0; i < reordered.size(); i++)
		{
			std::cout << YEL << "  [" << i << "] = (smaller: " << reordered[i].smaller 
				<< ", bigger: " << reordered[i].bigger << ")" << RES << std::endl;
		}
	}
	pairings = reordered;
	Container mainChain;
	mainChain.push_back(pairings[0].smaller); //first small goes first
	for (size_t i = 0; i < pairings.size(); i++)
	{
		mainChain.push_back(pairings[i].bigger);
		pairings[i].bound_pos = i + 1; //update bound position
	}
	if (debug) 
	{
		std::cout << YEL << "built mainChain with " << mainChain.size() << " els: [";
		for (size_t i = 0; i < mainChain.size(); i++)
		{
			std::cout << mainChain[i];
			if (i < mainChain.size() - 1) std::cout << ", ";
		}
		std::cout << "]" << RES << std::endl;
		std::cout << GRE << "bound positions set:" << RES << std::endl;
		for (size_t i = 0; i < pairings.size(); i++)
			std::cout << GRE << "  pairings[" << i << "].bound_pos = " << pairings[i].bound_pos << RES << std::endl;
	}
	std::vector<int> pending;
	std::vector<size_t> pending_bounds;
	for (size_t i = 1; i < pairings.size(); i++) 
	{
		pending.push_back(pairings[i].smaller);
		pending_bounds.push_back(pairings[i].bound_pos);
	}
	size_t stragg_idx = pending.size(); //idx for stragg
	if (oddseq) 
	{
		pending.push_back(strag);
		pending_bounds.push_back(mainChain.size());
	}
	if (pending.size() > 0)//insert all pending elements via Jacobsthal
	{
		std::vector<size_t> insertionOrder;
		if (pending.size() == 1)
			insertionOrder.push_back(0); //only one pending element
		else 
		{
			insertionOrder = buildInsertionOrder(pending.size() + 1); //generate JS order for pending.size() + 1, then adjust indices
			insertionOrder.erase(std::remove(insertionOrder.begin(), insertionOrder.end(), 0), insertionOrder.end()); //remove index 0
			for (size_t j = 0; j < insertionOrder.size(); j++) //adjust all indices from 1-based to 0-based pending array
				insertionOrder[j]--;
		}
		if (debug)
		{
			std::cout << CYA << "IV: jacobsthal insertion" << RES << std::endl;
			std::cout << CYA << pending.size() << " pending el to insert (incl. stragg if present)" << RES << std::endl;
			std::cout << CYA << "Jacobsthal insertion order: [";
			for (size_t k = 0; k < insertionOrder.size(); k++)
			{
				std::cout << insertionOrder[k];
				if (k < insertionOrder.size() - 1) std::cout << ", ";
			}
			std::cout << "]" << RES << std::endl;
		}
		for (size_t i = 0; i < insertionOrder.size(); i++) //execute insertions in Jacobsthal order
		{
			size_t idx = insertionOrder[i];
			int val = pending[idx];
			size_t bound = pending_bounds[idx];
			if (debug)
			{
				std::cout << CYA << "[step " << (i+1) << "] Insert pending[" << idx << "]";
				if (idx == stragg_idx && oddseq)
					std::cout << " (STRAGGLER)";
				std::cout << " = " << val << RES << std::endl;
				std::cout << CYA << "  Search bound: up to mainChain[" << bound << "]" << RES << std::endl;
			}
			size_t left = 0;
			size_t right = std::min(bound, mainChain.size()); //binary search using_bound_postition
			while (left < right)
			{
				size_t mid = left + (right - left) / 2;
				_co++;
				if (mainChain[mid] < val)
					left = mid + 1;
				else
					right = mid;
			}
			size_t insert_pos = left;
			if (debug)
			{
				std::cout << MAG << "  ➜ binary search result: insert at position " << insert_pos << RES << std::endl;
				std::cout << MAG << "  ➜ current mainChain: [";
				for (size_t k = 0; k < mainChain.size(); k++)
				{
					std::cout << mainChain[k];
					if (k < mainChain.size() - 1) std::cout << ", ";
				}
				std::cout << "]" << RES << std::endl;
			}
			mainChain.insert(mainChain.begin() + insert_pos, val);
			if (debug)
			{
				std::cout << MAG << "  ➜ After inserting " << val << ": [";
				for (size_t k = 0; k < mainChain.size(); k++)
				{
					std::cout << mainChain[k];
					if (k < mainChain.size() - 1) std::cout << ", ";
				}
				std::cout << "]" << RES << std::endl;
			}
			for (size_t j = 0; j < pending_bounds.size(); j++) //update bounds for remaining pending elements
			{
				if (j != idx && pending_bounds[j] >= insert_pos)
					pending_bounds[j]++;
			}
		}
	}
	if (debug)
	{
		std::cout << GRE << "✓ sortFJ COMPLETE" << RES << std::endl;
		std::cout << GRE << "Final size: " << mainChain.size() << std::endl;
		std::cout << GRE << "Result: [";
		for (size_t i = 0; i < mainChain.size(); i++)
		{
			std::cout << mainChain[i];
			if (i < mainChain.size() - 1) std::cout << ", ";
		}
		std::cout << "]" << RES << std::endl << std::endl;
	}
	container = mainChain;
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