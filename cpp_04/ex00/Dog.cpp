/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:16 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 17:03:31 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << MAG << "Dog Default constructed." << RES << std::endl;
}

Dog::Dog(std::string type)
{
	this->_type = type;
	std::cout << MAG << "Dog " << this->_type << " constructed." << RES << std::endl;
}

Dog::~Dog()
{
	std::cout << MAG << "Dog " << this->_type << " destructed." << RES << std::endl;
}

Dog::Dog(const Dog &copy)
{
	std::cout << MAG << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << MAG << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_type = copy._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << MAG << "Dog " << this->_type << " says barkbark!!!" << RES << std::endl;
}