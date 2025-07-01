/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/01 19:10:50 by hsetyamu         ###   ########.fr       */
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
- 42.75 × 256 = 10,944
- Store 10,944 in _fpval

### Retrieving the value:
- 10,944 ÷ 256 = 42.75

Storing the value 5.5:
- 5.5 × 256 = 1,408
- Store 1,408 in _fpval
*/