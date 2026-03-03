/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:47:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 14:22:29 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP //can be substituted with "#pragma once"
# define FIXED_HPP

# include <iostream>
# include <cmath>
/*
A copy constructor is a constructor which can be called with an argument of the
same class type and copies the content of the argument without mutating the
argument.
A copy assignment operator is a non-template non-static member function with the
name operator= that can be called with an argument of the same class type and
copies the content of the argument without mutating the argument.
*/
class Fixed
{
	private:
		int					_fpval;
		static const int	_fracbits = 8; //in-class initialization
	public:
		Fixed(); //default constr
		~Fixed(); //dest
		Fixed(const Fixed &copy); //copy constr
		Fixed	&operator=(const Fixed &copy); //assignment operator

		int		getRawBits(void) const; //getter
		void	setRawBits(int const raw); //setter

		Fixed(const int value); //int constr
		Fixed(const float value); //float constr
		int		toInt(void) const; //int getter
		float	toFloat(void) const; //float getter

		bool operator>(const Fixed &fix) const;
		bool operator<(const Fixed &fix) const;
		bool operator>=(const Fixed &fix) const;
		bool operator<=(const Fixed &fix) const;
		bool operator==(const Fixed &fix) const;
		bool operator!=(const Fixed &fix) const;
		Fixed operator+(const Fixed &fix) const;
		Fixed operator-(const Fixed &fix) const;
		Fixed operator*(const Fixed &fix) const;
		Fixed operator/(const Fixed &fix) const;
		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);
		static Fixed &min(Fixed &fix1, Fixed &fix2);
		static Fixed &max(Fixed &fix1, Fixed &fix2);
		static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
		static const Fixed &max(const Fixed &fix1, const Fixed &fix2);
};

std::ostream &operator << (std::ostream &out, const Fixed &fixed);

#endif