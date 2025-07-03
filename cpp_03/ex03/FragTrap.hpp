/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:20:32 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/03 17:53:45 by hsetyamu         ###   ########.fr       */
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
class	FragTrap : virtual public ClapTrap //virtual inheritance
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap	&operator=(const FragTrap &copy);

		void	attack(const std::string& target);  // Override ClapTrap's attack
		void	highFivesGuys();  // FragTrap specific method
};
