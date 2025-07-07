/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:09:42 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 14:05:19 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << CYA << "Brain Default constructed." << RES << std::endl;
}

Brain::Brain(const std::string *idea_arr, int size)
{
	std::cout << CYA << "Brain array constructed." << RES << std::endl;
	if (idea_arr)
	{
		for (int i = 0; i < size; i++)
			this->ideas[i] = idea_arr[i];
	}
	else
		std :: cout << "NULL idea array." << std :: endl;
}

Brain::~Brain()
{
	std::cout << CYA << "Brain destructed." << RES << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << CYA << "Copy constructor called." << RES << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << CYA << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.ideas[i];
	}
	return (*this);
}

std::string const	&Brain::getIdeas(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cerr << "Invalid index." << std::endl;
		return ("");
	}
	return (this->ideas[idx]);
}

void Brain::setIdeas(std::string idea, int idx)
{
	if (idx >= 0 && idx < 100)
		this->ideas[idx] = idea;
	else
		std::cerr << "Invalid index." << std::endl;
}
