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
	this->_brain = new Brain();
	std::cout << MAG << "Dog Default constructed." << RES << std::endl;
}

Dog::Dog(std::string type)
{
	this->_type = type;
	this->_brain = new Brain();
	std::cout << MAG << "Dog " << this->_type << " constructed." << RES << std::endl;
}

Dog::~Dog()
{
	std::cout << MAG << "Dog " << this->_type << " destructed." << RES << std::endl;
	if (this->_brain)
		delete (this->_brain);
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << MAG << "Copy constructor called." << RES << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << MAG << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		this->_type = copy._type;
		delete this->_brain; 
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << MAG << "Dog " << this->_type << " says barkbark!!!" << RES << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}

void Dog::setBrain(Brain *_brain)
{
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(_brain->getIdeas(i), i);
}
