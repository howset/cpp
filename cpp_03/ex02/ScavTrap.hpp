/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:40:35 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/03 16:10:43 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap //public inheritance
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
