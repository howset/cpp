/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 18:43:41 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int	main( void )
{
	ClapTrap dog("DogDog");
	ClapTrap cat("CatCat");

	//cat.attack("DogDog");
	dog.takeDamage(cat.attack("DogDog"));
	std::cout << "ClapTrap " << dog.getName() << " now has " << dog.getHp() << " hit points left." << std::endl;
	return 0;
}
