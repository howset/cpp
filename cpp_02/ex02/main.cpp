/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 15:14:56 by hsetyamu         ###   ########.fr       */
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
	int _fpval;						// The actual integer storage
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

/* void testConstructors()
{
	std::cout << std::endl;
	std::cout << "=== CONSTRUCTOR TESTS ===" << std::endl;

	Fixed a;					// Default constructor
	Fixed b(42);				// Int constructor
	Fixed c(3.14f);			// Float constructor
	Fixed d(c);				// Copy constructor

	std::cout << "Default (a): " << a << std::endl;
	std::cout << "Int 42 (b): " << b << std::endl;
	std::cout << "Float 3.14 (c): " << c << std::endl;
	std::cout << "Copy of c (d): " << d << std::endl;
}

void testAssignment()
{
	std::cout << std::endl;
	std::cout << "=== ASSIGNMENT TESTS ===" << std::endl;

	Fixed a(5.5f);
	Fixed b(2.2f);
	Fixed c;

	c = a;  // Assignment operator
	std::cout << "Before assignment - a: " << a << ", c: " << c << std::endl;
	a = b;  // Self-assignment test
	std::cout << "After a = b - a: " << a << ", b: " << b << std::endl;
	a = a;  // Self-assignment
	std::cout << "After a = a (self-assignment): " << a << std::endl;
}

void testComparisons()
{
	std::cout << std::endl;
	std::cout << "=== COMPARISON TESTS ===" << std::endl;

	Fixed a(5.5f);
	Fixed b(2.2f);
	Fixed c(5.5f);

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= c: " << (a >= c) << std::endl;
	std::cout << "a <= c: " << (a <= c) << std::endl;
	std::cout << "a == c: " << (a == c) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
}

void testArithmetic()
{
	std::cout << std::endl;
	std::cout << "=== ARITHMETIC TESTS ===" << std::endl;

	Fixed a(10.5f);
	Fixed b(2.5f);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	// Test with negative numbers
	Fixed c(-3.5f);
	std::cout << "c = " << c << std::endl;
	std::cout << "a + c = " << (a + c) << std::endl;
	std::cout << "a * c = " << (a * c) << std::endl;
}
//floating point precision limitation
// in c++, float typically uses 32 bits with about 6-7 decimal digits of precision
void testIncrementDecrement()
{
	std::cout << std::endl;
	std::cout << "=== INCREMENT/DECREMENT TESTS ===" << std::endl;

	Fixed a(5.0f);

	std::cout << "Initial a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a after pre-increment: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a after post-increment: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a after pre-decrement: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a after post-decrement: " << a << std::endl;
}

void testMinMax()
{
	std::cout << std::endl;
	std::cout << "=== MIN/MAX TESTS ===" << std::endl;

	Fixed a(10.5f);
	Fixed b(20.25f);
	const Fixed c(5.75f);
	const Fixed d(15.125f);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "Fixed::max(c, d) = " << Fixed::max(c, d) << std::endl;
	std::cout << "Fixed::min(c, d) = " << Fixed::min(c, d) << std::endl;
}

void testConversions()
{
	std::cout << std::endl;
	std::cout << "=== CONVERSION TESTS ===" << std::endl;

	Fixed a(42.75f);
	Fixed b(-10);

	std::cout << "a = " << a << std::endl;
	std::cout << "a.toInt() = " << a.toInt() << std::endl;
	std::cout << "a.toFloat() = " << a.toFloat() << std::endl;
	std::cout << "a.getRawBits() = " << a.getRawBits() << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b.toInt() = " << b.toInt() << std::endl;
	std::cout << "b.toFloat() = " << b.toFloat() << std::endl;
	std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;
}

void testOtherCases()
{
	std::cout << std::endl;
	std::cout << "=== OTHER TESTS ===" << std::endl;
	
	Fixed zero(0);
	Fixed small(0.00390625f);  // Smallest representable: 1/256
	Fixed large(100.99f);

	std::cout << "Zero: " << zero << std::endl;
	std::cout << "Smallest (1/256): " << small << std::endl;
	std::cout << "Large: " << large << std::endl;
	std::cout << "zero == 0: " << (zero == Fixed(0)) << std::endl;
	std::cout << "small * 256: " << (small * Fixed(256)) << std::endl;
	// Test division by very small number
	std::cout << "large / small: " << (large / small) << std::endl;
}

void testChaining()
{
	std::cout << std::endl;
	std::cout << "=== CHAINING TESTS ===" << std::endl;

	Fixed a(5.0f);
	Fixed b(2.0f);
	Fixed c(3.0f);

	std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;

	// Complex expression
	Fixed result = (a + b) * c - Fixed(1.5f);
	std::cout << "(a + b) * c - 1.5 = " << result << std::endl;
	// Fix: Compare bool result with bool, not Fixed
	std::cout << "a < b: " << (a < b) << ", b < c: " << (b < c) << std::endl;
	std::cout << "(a < b) && (b < c): " << ((a < b) && (b < c)) << std::endl;
	// Fix: Use proper chained increments
	std::cout << "Original a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "++a again: " << ++a << std::endl;  // Increment twice separately
	std::cout << "Final a: " << a << std::endl;
}

int main(void)
{
	testConstructors();
	testAssignment();
	testComparisons();
	testArithmetic();
	testIncrementDecrement();
	testMinMax();
	testConversions();
	testOtherCases();
	testChaining();

	std::cout << std::endl;
	std::cout << "=== ORIGINAL TEST ===" << std::endl;

	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
} */