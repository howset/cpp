/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 15:58:49 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Try again" << std::endl;
		return (1);
	}
	else
	{
		level = argv[1];
		harl.complain(level);
	}
	return (0);
}