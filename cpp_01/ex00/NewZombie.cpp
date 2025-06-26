/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:48 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 19:16:29 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*NewZombie(std::string name)
{
	Zombie *zombie;
	
	zombie = new Zombie(name); //on heap, must be deleted
	return (zombie);
}