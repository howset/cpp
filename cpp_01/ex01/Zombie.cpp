/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:21 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 19:16:03 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	//this->name = "";
	std::cout << "Zombie created (noname)." << std::endl;
}

/* Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie " << this->name << " created." << std::endl;
} */

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": Moar brainz!" << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName() const
{
	return (this->name);
}