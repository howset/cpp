/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 18:06:26 by hsetyamu         ###   ########.fr       */
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