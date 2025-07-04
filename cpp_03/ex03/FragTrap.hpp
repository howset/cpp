/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:20:32 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 11:41:47 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

/*
The `virtual` keyword ensures that only **one instance** of `ClapTrap` exists 
in the final `DiamondTrap` object, eliminating the ambiguity. When using virtual
inheritance, `DiamondTrap` becomes responsible for directly initializing the `
ClapTrap` base class in its constructor's initialization list, even though it's
not a direct base class.

Without virtual inheritance:
DiamondTrap object:
├── ScavTrap part
│   └── ClapTrap part (copy 1)
└── FragTrap part
    └── ClapTrap part (copy 2)  ← DUPLICATE!

With virtual inheritance:
DiamondTrap object:
├── ScavTrap part (points to shared ClapTrap)
├── FragTrap part (points to shared ClapTrap)
└── Shared ClapTrap part (single instance)

Constructor order with virtual inheritance:
1. ClapTrap constructor (most derived class calls it directly)
2. ScavTrap constructor (skips ClapTrap - already constructed)
3. FragTrap constructor (skips ClapTrap - already constructed)  
4. DiamondTrap constructor
*/
class	FragTrap : virtual public ClapTrap //virtual inheritance
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap	&operator=(const FragTrap &copy);

		void	attack(const std::string& target); //override
		void	highFivesGuys();
};
