/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:41:55 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/02 18:41:39 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hp;
	int			_ep;
	int			_ad;
public:
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap &copy); //copy constr
	ClapTrap	&operator=(const ClapTrap &copy); //assignment operator

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string const	&getName(void) const;
	int const			&getHp(void) const;
};

