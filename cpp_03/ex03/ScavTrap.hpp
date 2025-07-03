/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:40:35 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/03 17:53:39 by hsetyamu         ###   ########.fr       */
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
*/
class	ScavTrap : virtual public ClapTrap //virtual inheritance
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap	&operator=(const ScavTrap &copy);

		void	attack(const std::string& target);  // Override ClapTrap's attack
		void	guardGate();  // ScavTrap specific method
};
