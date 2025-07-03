/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/03 18:33:09 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

#include <iostream>

int	main(void)
{
	DiamondTrap diamond1("FrogFrog");
	DiamondTrap diamond2("HawkHawk");
	DiamondTrap diamond3 = diamond1;

	diamond3.setName("FrogFrogFrog");

	// Display DiamondTrap stats - should have mixed inheritance
	std::cout << std::endl;
	std::cout << "####### Stats #######" << std::endl;
	std::cout << "DiamondTrap " << diamond1.getName() << " has " << diamond1.getHp() << " HP, " 
			<< diamond1.getEp() << " EP, " << diamond1.getAd() << " AD" << std::endl;
	std::cout << "DiamondTrap " << diamond2.getName() << " has " << diamond2.getHp() << " HP, " 
			<< diamond2.getEp() << " EP, " << diamond2.getAd() << " AD" << std::endl;
	std::cout << "DiamondTrap " << diamond3.getName() << " has " << diamond3.getHp() << " HP, " 
			<< diamond3.getEp() << " EP, " << diamond3.getAd() << " AD" << std::endl;

	std::cout << std::endl;
	std::cout << "####### whoAmI test #######" << std::endl;
	diamond1.whoAmI();
	diamond2.whoAmI();
	//diamond3.whoAmI();

	//attacking
	std::cout << std::endl;
	std::cout << "####### Attacking #######" << std::endl;
	diamond1.attack("Enemy");
	diamond2.takeDamage(2);
	std::cout << "DiamondTrap " << diamond2.getName() << " now has " << diamond2.getHp() << " hit points left." << std::endl;

	//inherited special abilities
	std::cout << std::endl;
	std::cout << "####### Inherited abilities #######" << std::endl;
	diamond1.guardGate();
	diamond1.highFivesGuys();

	//copy assignment
	std::cout << std::endl;
	std::cout << "####### DiamondTrap copy assignment #######" << std::endl;
	diamond3 = diamond2;
	std::cout << "After assignment, " << diamond3.getName() << " has " << diamond3.getHp() << " HP" << std::endl;
	diamond3.whoAmI();

	//repairing
	std::cout << std::endl;
	std::cout << "####### DiamondTrap repairing #######" << std::endl;
	diamond2.beRepaired(20);
	std::cout << "DiamondTrap " << diamond2.getName() << " now has " << diamond2.getHp() << " hit points after repair." << std::endl;

	std::cout << std::endl;
	return 0;
}
