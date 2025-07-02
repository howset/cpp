/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:41:57 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 16:25:32 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " constructed" << std::endl;

}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	//_fpval = copy._fpval;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	//if (this != &copy) //best practice to check for self-assignment
	//	_fpval = copy._fpval;
	//return (*this);
}

void attack(const std::string& target)
{
	ClapTrap <name> attacks <target>, causing <damage> points of damage!
}

void takeDamage(unsigned int amount)
{}

void beRepaired(unsigned int amount)
{}