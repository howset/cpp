/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:40:35 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/04 11:42:01 by hsetyamu         ###   ########.fr       */
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
class	ScavTrap : virtual public ClapTrap //virtual inheritance
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap	&operator=(const ScavTrap &copy);

		void	attack(const std::string& target); //override
		void	guardGate();
};
