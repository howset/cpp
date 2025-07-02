/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:47:45 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 13:26:35 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//out-of-class definition, alternative to declare that _fracboits has value 8
//const int	Fixed::_fracbits = 8;

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

/**
 * Creates a new Fixed object as a copy of an existing one.
 * Copies the internal fixed-point value from the source object.
 * Ex: Fixed b = a --> create a new obj from an existing one
 */
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_fpval = copy._fpval;
}

/**
 * This operator assigns the value of another Fixed object to this object.
 * It first checks for self-assignment, and if the objects are not the same,
 * it copies the internal fixed-point value from the source object.
 * Ex: b = a --> assign a val from an existing obj to another existing obj
 */
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