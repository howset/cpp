/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 11:24:12 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int	main(void)
{
	ClapTrap dog("DogDog");
	ClapTrap cat("CatCat");
	ClapTrap dog2 = dog;

	dog2.setName("DogDogDog");
	
	//attacking and taking damage
	std::cout << std::endl;
	std::cout << "####### attacking and taking damage #######" <<std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		cat.attack("DogDog");
		dog.takeDamage(1);
		std::cout << "ClapTrap " << dog.getName() << " now has " << dog.getHp()
			<< " hit points left." << std::endl;
	}
	std::cout << "ClapTrap " << cat.getName() << " now has " << cat.getEp() << " energy points left." << std::endl;
	
	//repairing
	std::cout << std::endl;
	std::cout << "####### repairing #######" <<std::endl;
	cat.beRepaired(1);
	for (int i = 0; i < 5; i++)
	{
		std::cout << std::endl;
		dog.beRepaired(1);
	}

	//final stats
	std::cout << std::endl;
	std::cout << "####### end condition #######" <<std::endl;
	std::cout << "ClapTrap " << dog.getName() << " now has " << dog.getHp() <<
		" hit points left." << std::endl;
	std::cout << "ClapTrap " << dog.getName() << " now has " << dog.getEp() <<
		" energy points left." << std::endl;

	std::cout << "ClapTrap " << cat.getName() << " now has " << cat.getHp() <<
		" hit points left." << std::endl;
	std::cout << "ClapTrap " << cat.getName() << " now has " << cat.getEp() <<
		" energy points left." << std::endl;
	
	std::cout << "ClapTrap " << dog2.getName() << " now has " << dog2.getHp()
		<< " hit points left." << std::endl;
	std::cout << "ClapTrap " << dog2.getName() << " now has " << dog2.getEp()
		<< " energy points left." << std::endl;
	
	std::cout << std::endl;
	return 0;
}
