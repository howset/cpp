/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 15:13:25 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main( void ) {
	
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f ); //permanent
	Fixed const d( b );

	a = Fixed( 1234.4321f ); //temporary (?) & mutable
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;
	
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