/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 15:07:09 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main( void ) {
	Fixed a;									//Default constructor called
	Fixed b( a );								//Copy constructor called
	Fixed c;									//Default constructor called

	c = b;										//Copy assignment operator called

	std::cout << a.getRawBits() << std::endl;	//getRawBits member function called 0
	std::cout << b.getRawBits() << std::endl;	//getRawBits member function called 0
	std::cout << c.getRawBits() << std::endl;	//getRawBits member function called 0

/* 	a.setRawBits(42);
	std::cout << "After setting a to 42: " << a.getRawBits() << std::endl;
	b.setRawBits(1024); //represents 1024/256 = 4.0 in fixed-point
	std::cout << "After setting b to 1024: " << b.getRawBits() << std::endl;
	c.setRawBits(-256); //represents -256/256 = -1.0 in fixed-point
	std::cout << "After setting c to -256: " << c.getRawBits() << std::endl; */

												//Destructor called x3
	return 0;
}

/*
A fixed-point number is a way to represent fractional (decimal) numbers using 
only integers, which is particularly useful when you don't have floating-point 
hardware or need predictable precision.

How Fixed-Point Works:
Instead of storing the actual decimal value, you store an integer that 
represents the value scaled up by a fixed power of 2.

Class Example:
	int _fpval;                    // The actual integer storage
	static const int _fracbits = 8; // Number of fractional bits

With _fracbits = 8, you're using 8 bits for the fractional part. This means:
- You scale numbers by 2^8 = 256
- The smallest representable fraction is 1/256 = 0.00390625

### Conversion Examples:
Storing the value 42.75:
- 42.75 × 256 = 10944
- Store 10944 in _fpval

### Retrieving the value:
- 10944 ÷ 256 = 42.75

Storing the value 5.5:
- 5.5 × 256 = 1408
- Store 1408 in _fpval
*/