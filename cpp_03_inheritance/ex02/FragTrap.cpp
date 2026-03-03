/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:20:29 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 10:57:04 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << YEL << "FragTrap Default constructed." << RES << std::endl;
}

//FragTrap::FragTrap(std::string name) //go for the default const in ClapTrap
FragTrap::FragTrap(std::string name) : ClapTrap(name) //go for the nondefault const in ClapTrap
{
	this->setName(name);
	std::cout << YEL << "FragTrap " << this->getName() << " constructed." << RES << std::endl;
	//this->_hp = 100; //works for protected attributes
	//this->_ep = 100; //works for protected attributes
	//this->_ad = 30; //works for protected attributes
	this->setHp(100);
	this->setEp(100);
	this->setAd(30);
}

FragTrap::~FragTrap()
{
	std::cout << YEL << "FragTrap " << this->getName() << " destructed." << RES << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << YEL << "FragTrap copy constructor called." << RES << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << YEL << "FragTrap copy assignment operator called." << RES << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy); //call base class assignment
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (this->getHp() <= 0)
	{
		std::cout << YEL << "FragTrap " << this->getName() << " has no more hit points!" << RES << std::endl;
		return ;
	}
	if (this->getEp() > 0)
	{
		std::cout << YEL << "FragTrap " << this->getName() << " attacks " << target << " causing " << this->getAd() << " points of damage!" << RES << std::endl;
		this->setEp(this->getEp() - 1);
	}
	else
		std::cout << YEL << "FragTrap " << this->getName() << " has no more energy points!" << RES << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << YEL << "FragTrap " << this->getName() << " requests a high five. (please)" << RES << std::endl;
}