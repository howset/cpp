/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 18:40:33 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main( void ) {
	
	Fixed			a;
	Fixed const		b(Fixed( 5.05f ) * Fixed( 2 ));

	std::cout <<  a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

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
Looking at your Fixed class:
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