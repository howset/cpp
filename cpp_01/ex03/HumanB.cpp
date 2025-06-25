/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:40:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/25 19:50:03 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*
This constructor uses a member initializer list to efficiently set the name and
 initialize the weapon pointer to NULL, allowing HumanB objects to exist without
 a weapon initially. The syntax : name(name), weapon(NULL) directly initializes
 members during construction rather than assigning values later.
*/
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " attacks with " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with hands and teeth." << std::endl;
}