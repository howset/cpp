/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:40:32 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 10:56:35 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << MAG << "ScavTrap Default constructed." << RES << std::endl;
}

//ScavTrap::ScavTrap(std::string name) //go for the default const in ClapTrap
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) //go for the nondefault const in ClapTrap
{
	this->setName(name);
	std::cout << MAG << "ScavTrap " << this->getName() << " constructed." << RES << std::endl;
	//this->_hp = 100; //works for protected attributes
	//this->_ep = 50; //works for protected attributes
	//this->_ad = 20; //works for protected attributes
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << MAG << "ScavTrap " << this->getName() << " destructed." << RES << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << MAG << "ScavTrap copy constructor called." << RES << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << MAG << "ScavTrap copy assignment operator called." << RES << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy); //call base class assignment
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHp() <= 0)
	{
		std::cout << MAG << "ScavTrap " << this->getName() << " has no more hit points!" << RES << std::endl;
		return ;
	}
	if (this->getEp() > 0)
	{
		std::cout << MAG << "ScavTrap " << this->getName() << " attacks " << target << " causing " << this->getAd() << " points of damage!" << RES << std::endl;
		this->setEp(this->getEp() - 1);
	}
	else
		std::cout << MAG << "ScavTrap " << this->getName() << " has no more energy points!" << RES << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << MAG << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << RES << std::endl;
}