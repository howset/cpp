/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:09 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 13:07:44 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << GRE << "Cat Default constructed." << RES << std::endl;
}

Cat::Cat(std::string type)
{
	this->_type = type;
	std::cout << GRE << "Cat " << this->_type << " constructed." << RES << std::endl;
}

Cat::~Cat()
{
	std::cout << GRE << "Cat " << this->_type << " destructed." << RES << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << GRE << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << GRE << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_type = copy._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << GRE << "Cat " << this->_type << " says meowmeow." << RES << std::endl;
}