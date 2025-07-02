/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:47:45 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 13:32:32 by hsetyamu         ###   ########.fr       */
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

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpval = value * 256;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpval = roundf(value * 256.0f); //round to the nearest integer
}

int		Fixed::toInt(void) const
{
	//return (_fpval >> _fracbits); //divide by 256 (2^8) (bit shift??)
	return (_fpval / 256); //direct division by 256
}

float	Fixed::toFloat(void) const
{
	//return ((float)_fpval / (1 << _fracbits)); //divide by 256.0f
	return ((float)_fpval / 256.0f); //makes more sense heh
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}