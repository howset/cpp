/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:59 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 11:47:15 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

/*
https://cplusplus.com/doc/tutorial/classes/

access specifiers (modify the access rights for the members that follow them): 
- private: accessible only from within other members of the same class
- public: accessible from anywhere where the object is visible
- protected: accessible from other members of the same class (also from members of
	 their derived classes)
*/
class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce();
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif