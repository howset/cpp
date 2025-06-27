/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:26 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 11:19:24 by hsetyamu         ###   ########.fr       */
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
		//Zombie(); //uncomment for non default constructor
		//Zombie(std::string name); //from ex00
		~Zombie();
		void	announce();
		void	setName(std::string name); //setter
		std::string	getName() const; //getter
};

Zombie*	zombieHorde(int N, std::string name);

#endif