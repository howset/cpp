/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:35:05 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 19:15:41 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*
This constructor takes both a name and a weapon reference as parameters, using a
 member initializer list to set the name and bind the weapon reference to the 
 provided weapon. Unlike HumanB, HumanA must always have a weapon since
 references cannot be null and must be initialized at construction.
*/
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}

void	HumanA::attack()
{
	std::cout << name << " attacks with " << weapon.getType() <<  std::endl;
}