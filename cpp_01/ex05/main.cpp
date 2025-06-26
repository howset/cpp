/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 19:51:04 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl	harl;
	std::string	level;

	level = argv[1];
	if (argc == 2)
		harl.complain(level);
	else
		std::cout << "Unrecognized complain" << std::endl;
}