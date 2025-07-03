/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:41:57 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 18:40:47 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " constructed." << std::endl;
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 1;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		this->_name = copy._name;
		this->_hp = copy._hp;
		this->_ep = copy._ep;
		this->_ad = copy._ad;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no more hit points!" << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_ad  << " points of damage!"<< std::endl;
		this->_ep--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no more energy points!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " point(s) of damage!" << std::endl;
		this->_hp = this->_hp - amount;
		if (this->_hp < 0)
			this->_hp = 0;
	}
	else if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " has no more hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 10)
		std::cout << "ClapTrap " << this->_name << " is healthy." << std::endl;
	if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " heals " << amount << " hit point(s)." << std::endl;
		this->_hp = this->_hp + amount;
		this->_ep--;
	}
	else if (this->_hp <= 0 || this->_ep <= 0)
		std::cout << "ClapTrap " << this->_name << " can't do anything." << std::endl;
}

std::string const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

int const	&ClapTrap::getHp(void) const
{
	return (this->_hp);
}