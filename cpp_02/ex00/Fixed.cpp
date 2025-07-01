/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:47:45 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/01 19:22:31 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//const int	Fixed::_fracbits = 8; //alternative to declare that _fracboits has value 8

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fpval = 0;
}

//this one works too
// Fixed::Fixed(void): _fpval(0)
// {
// 	std::cout << "Default constructor called" << std::endl; 
// }

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_fpval = copy._fpval;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		_fpval = copy._fpval;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	_fpval = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fpval);
}