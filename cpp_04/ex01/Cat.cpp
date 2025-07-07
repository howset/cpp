/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:09 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 15:09:29 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_brain = new Brain();
	std::cout << GRE << "Cat Default constructed." << RES << std::endl;
}

Cat::Cat(std::string type)
{
	this->_type = type;
	this->_brain = new Brain();
	std::cout << GRE << "Cat " << this->_type << " constructed." << RES << std::endl;
}

Cat::~Cat()
{
	std::cout << GRE << "Cat " << this->_type << " destructed." << RES << std::endl;
	if (this->_brain)
		delete (this->_brain);
}

Cat::Cat(const Cat &copy)
{
	std::cout << GRE << "Copy constructor called." << RES << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << GRE << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		this->_type = copy._type;
		delete this->_brain; 
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << GRE << "Cat " << this->_type << " says meowmeow." << RES << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}

void Cat::setBrain(Brain *_brain)
{
	for (int i = 0; i < 100; i++)
		this->_brain->setIdeas(_brain->getIdeas(i), i);
}