/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:41:57 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 16:56:32 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

	{
		this->_name = copy._name;
		this->_hp = copy._hp;
		this->_ep = copy._ep;
		this->_ad = copy._ad;
	}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hp <= 0)
	{
		std::cout << CYA << "ClapTrap " << this->_name << " has no more hit points!" << RES << std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout << CYA << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_ad  << " points of damage!" << RES << std::endl;
		this->_ep--;
	}
	else
		std::cout << CYA << "ClapTrap " << this->_name << " has no more energy points!" << RES << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		std::cout << CYA << "ClapTrap " << this->_name << " took " << amount << " point(s) of damage!" << RES << std::endl;
		this->_hp = this->_hp - amount;
		if (this->_hp < 0)
			this->_hp = 0;
	}
	else if (this->_hp <= 0)
		std::cout << CYA << "ClapTrap " << this->_name << " has no more hit points!" << RES << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp == 10)
	{
		std::cout << CYA << "ClapTrap " << this->_name << " is healthy." << RES << std::endl;
		return ;
	}
		if (this->_hp > 0 && this->_ep > 0)
	{
		std::cout << CYA << "ClapTrap " << this->_name << " heals " << amount << " hit point(s)." << RES << std::endl;
		this->_hp = this->_hp + amount;
		this->_ep--;
	}
	else if (this->_hp <= 0 || this->_ep <= 0)
		std::cout << CYA << "ClapTrap " << this->_name << " can't do anything." << RES << std::endl;
}

std::string const	&ClapTrap::getName(void) const
{
	return (this->_name);
}

int const	&ClapTrap::getHp(void) const
{
	return (this->_hp);
}

int const	&ClapTrap::getEp(void) const
{
	return (this->_ep);
}

int const	&ClapTrap::getAd(void) const
{
	return (this->_ad);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void ClapTrap::setHp(int hp)
{
	this->_hp = hp;
}

void ClapTrap::setEp(int ep)
{
	this->_ep = ep;
}

void ClapTrap::setAd(int ad)
{
	this->_ad = ad;
}