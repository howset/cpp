/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:08 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 16:28:28 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//out-of-class definition, alternative to declare that _fracboits has value 8
//const int	Fixed::_fracbits = 8;

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
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
	//std::cout << "Copy constructor called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		_fpval = copy._fpval;
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	_fpval = raw;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_fpval);
}

Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	//this->_fpval = value << _fracbits;
	this->_fpval = value * 256;
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	//this->_fpval = roundf(value * (1 << _fracbits));
	this->_fpval = roundf(value * 256.0f);
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

bool Fixed::operator>(const Fixed &fix) const
{
	if (_fpval > fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &fix) const
{
	if (_fpval < fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &fix) const 
{
	if (_fpval >= fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &fix) const
{
	if (_fpval <= fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &fix) const
{
	if (_fpval == fix.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &fix) const
{
	if (_fpval != fix.getRawBits())
		return (true);
	return (false);
}

/**
 * This operator returns a new Fixed object whose value is the sum of
 * the floating-point representations of the current object and the given
 * Fixed object.
 */
Fixed Fixed::operator+(const Fixed &fix) const
{
	return (Fixed(this->toFloat() + fix.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fix) const
{
	return (Fixed(this->toFloat() - fix.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fix) const
{
	return (Fixed(this->toFloat() * fix.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fix) const
{
	return (Fixed(this->toFloat() / fix.toFloat()));
}

/**
 * Pre-increment
 * Increments the internal fixed-point value by 1 and returns a reference to 
 * the updated object.
 */
Fixed &Fixed::operator++()
{
	this->_fpval++;
	return (*this);
}

/**
 * Post-increment
 * Creates a copy of the current object, increments the value of the current object,
 * and returns the original (pre-incremented) value.
 * (int) is unused dummy parameter to distinguish post-increment from pre-increment.
 */
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->_fpval--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

const Fixed &Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 < fix2)
		return (fix1);
	return (fix2);
}

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 > fix2)
		return (fix1);
	return (fix2);
}

std::ostream &operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

