#pragma once

# include <iostream>
# include <vector>
# include <deque>
# include <sys/time.h> //gettimeofday
# include <ctime> //std::time
# include <iomanip> //setprecision
# include <algorithm> //atoi

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

struct IndexedPair {
    int smaller;
    int larger;
    size_t uniqueID;
};

class PmergeMe
{
	private:
		static size_t _nextID;
		std::vector<int> _ori;
		std::vector<int> _vec;
		std::deque<int> _deq;
		size_t _comps;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);

		void parseInput(int argc, char *argv[]);
		
		void sortNums(void);
		void sortVec(std::vector<int> &_vec);
		void sortDeq(std::deque<int> &_deq);
		void sortIndexedPairs(std::vector<IndexedPair> &pairs);
		void insertBinaryIndexedPair(std::vector<IndexedPair> &chain, const IndexedPair &toInsert);

		void mergeSortPairs(std::vector<std::pair<int, int> > &pairs, int left, int right);
		void mergePairs(std::vector<std::pair<int, int> > &pairs, int left, int mid, int right);

		std::vector<size_t> genJS(size_t n);
		void insertBinary(std::vector<int> &chain, int value);

		void runTest(void); //in test.cpp

		template <typename Container>
		void printSeq(std::string when, Container &cont, bool trunc);
};