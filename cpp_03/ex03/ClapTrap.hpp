/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:41:55 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/03 17:56:30 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

class	ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy); //copy constr
		ClapTrap	&operator=(const ClapTrap &copy); //assignment operator
	
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	
		std::string const	&getName(void) const;
		int const			&getHp(void) const;
		int const			&getEp(void) const;
		int const			&getAd(void) const;
	
		void				setName(std::string name);
		void				setHp(int hp);
		void				setEp(int ep);
		void				setAd(int ad);
};

