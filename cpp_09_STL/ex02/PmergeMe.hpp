#pragma once
# include <iostream>
# include <vector>
# include <deque>
# include <algorithm> //find etc
# include <iomanip> //setprecision
# include <sys/time.h> //gettimeofday


class PmergeMe
{
private:
	std::vector<int> _ori;
	std::vector<int> _vec;
	std::deque<int> _deq;
	
	template <typename Container>
	void sortFJ(Container &container);
	template <typename Container>
	void insertLosers(Container &main, const Container &pending);
	std::vector<size_t> generateJS(size_t n);
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);

	void parseInput(int argc, char **argv);
	void sortNums();
	void displayRes() const;
};