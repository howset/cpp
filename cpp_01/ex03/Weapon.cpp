/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:31:03 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 15:09:52 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	//this->name = "";
	std::cout << "Weapon constructed." << std::endl;
}

// Weapon::~Weapon()
// {
// 	std::cout << "Weapon " << this->type << " destructed." << std::endl;
// }

//Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

/*
const at the end is est practice for getter functs, only read data without
changing the obj's state. const member function doesn't modify any member
variables of the obj.
*/
const std::string& Weapon::getType() const
{
	return (this->type);
}