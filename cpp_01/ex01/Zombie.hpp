/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:26 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 18:21:08 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

/*
The `const` keyword at the end means this function doesn't modify the object's 
state - it's a read-only operation, which is appropriate for a getter function.
*/

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie();
		//Zombie(std::string name);
		~Zombie();
		void	announce();
		void	setName(std::string name);
		std::string	getName() const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif