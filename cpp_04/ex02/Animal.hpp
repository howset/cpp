/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:06 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 17:01:18 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

/*
virtual keyword on dest:potential mem leak when deleting objs through base
class pointers
*/
/*
Abstract class is made by adding at least one pure virtual function.
pure virtual function: has no implementation in the base class and has to be 
overridden by the derived classes.
*/
class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal(); //virtual
		Animal(const Animal &copy); //copy constr
		Animal	&operator=(const Animal &copy); //assignment operator

		virtual void		makeSound() const = 0; //pure virtual function

		std::string const	&getType() const;
		void				setType(std::string type);
};
