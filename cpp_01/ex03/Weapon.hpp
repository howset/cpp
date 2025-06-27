/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:28:34 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 15:10:11 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string type);
		//~Weapon(); //using a default destructor
		const std::string&	getType() const; //getter
		void		setType(std::string name);
};

#endif