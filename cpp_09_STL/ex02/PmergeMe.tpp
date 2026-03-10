#pragma once

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