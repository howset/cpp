/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:00:44 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 19:16:33 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *zombie;

	zombie = newZombie("Gecko (heap)");
	zombie->announce();
	delete zombie;
	std::cout << std::endl;
	randomChump("Gecki (stack)");
	return (0);
}