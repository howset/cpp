/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/03 17:35:11 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int	main(void)
{
	ScavTrap rat("RatRat");
	ScavTrap duck("DuckDuck");
	ScavTrap rat2 = rat;

	rat2.setName("RatRatRat");

	//initial stats
	std::cout << std::endl;
	std::cout << "####### Initial stats #######" << std::endl;
	std::cout << rat.getName() << " has " << rat.getHp() << " HP, " 
			<< rat.getEp() << " EP, " << rat.getAd() << " AD" << std::endl;
	std::cout << duck.getName() << " has " << duck.getHp() << " HP, " 
			<< duck.getEp() << " EP, " << duck.getAd() << " AD" << std::endl;

	//attacking
	std::cout << std::endl;
	std::cout << "####### ScavTrap attacking #######" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;
		rat.attack("Enemy"); //overridden
		duck.takeDamage(20); //not overridden
		std::cout << "ScavTrap " << duck.getName() << " now has " << duck.getHp() << " hit points left." << std::endl;
	}

	//repairing
	std::cout << std::endl;
	std::cout << "####### ScavTrap repairing #######" << std::endl;
	duck.beRepaired(30);
	std::cout << "ScavTrap " << duck.getName() << " now has " << duck.getHp() << " hit points after repair." << std::endl;

	//guardGate function
	std::cout << std::endl;
	std::cout << "####### ScavTrap guarding gate #######" << std::endl;
	rat.guardGate();
	duck.guardGate();
	rat2.guardGate();
	
	//final stats
	std::cout << std::endl;
	std::cout << "####### Final stats #######" << std::endl;
	std::cout << "ScavTrap " << rat.getName() << " has " << rat.getHp() << " HP, " 
			<< rat.getEp() << " EP left" << std::endl;
	std::cout << "ScavTrap " << duck.getName() << " has " << duck.getHp() << " HP, " 
			<< duck.getEp() << " EP left" << std::endl;
	std::cout << "ScavTrap " << rat2.getName() << " has " << rat2.getHp() << " HP, " 
			<< rat2.getEp() << " EP left" << std::endl;

	std::cout << "========== COMPARISON ==========" << std::endl;

	ScavTrap scav("CowCow");
	FragTrap frag("PigPig");

	std::cout << std::endl;
	std::cout << "####### Stats #######" << std::endl;
	std::cout << "ScavTrap " << scav.getName() << ": HP=" << scav.getHp() 
			<< ", EP=" << scav.getEp() << ", AD=" << scav.getAd() << std::endl;
	std::cout << "FragTrap " << frag.getName() << ": HP=" << frag.getHp() 
			<< ", EP=" << frag.getEp() << ", AD=" << frag.getAd() << std::endl;

	std::cout << std::endl;
	std::cout << "####### Special Abilities Comparison #######" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << std::endl;
	std::cout << "####### Attacking Comparison #######" << std::endl;
	scav.attack("TestTarget");
	frag.attack("TestTarget");

	std::cout << std::endl;
	return 0;
}
