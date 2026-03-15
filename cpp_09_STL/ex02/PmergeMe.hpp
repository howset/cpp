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

# include "PmergeMe.tpp" 