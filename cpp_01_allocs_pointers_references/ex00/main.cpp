/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 11:20:22 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
main as test
*/
int	main()
{
	Zombie *zombie;

	//newZombie on heap, must be deleted
	zombie = newZombie("Gecko (heap)");
	zombie->announce();
	delete zombie;
	
	std::cout << std::endl;
	
	//randomChump is on stack
	randomChump("Gecki (stack)");
	return (0);
}