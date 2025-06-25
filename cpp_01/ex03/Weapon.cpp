/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:31:03 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/25 18:55:00 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	//this->name = "";
	std::cout << "Weapon created." << std::endl;
}

// Weapon::~Weapon()
// {
// 	std::cout << "Weapon " << this->type << " destroyed." << std::endl;
// }

//Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType() const
{
	return (this->type);
}