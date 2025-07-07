/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:08:01 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 17:03:09 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << YEL << "WrongCat Default constructed." << RES << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	this->_type = type;
	std::cout << YEL << "WrongCat " << this->_type << " constructed." << RES << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << YEL << "WrongCat " << this->_type << " destructed." << RES << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << YEL << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << YEL << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_type = copy._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << YEL << "WrongCat " << this->_type << " says meowmeow!!!" << RES << std::endl;
}