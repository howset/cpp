/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/26 20:07:40 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;
	std::string level;

	if (argc != 2)
		std::cout << "Unrecognized complaint" << std::endl;
	else
	{
		level = argv[1];
		for (size_t i = 0; i < level.length(); ++i) 
			level[i] = toupper(level[i]);
		for (i = 0; i < 4; i++)
			if (levels[i] == level)
				break;
		switch (i)
		{
			case 0:
				while(i < 4)
					harl.complain(levels[i++]);
				break;
			case 1:
				while(i < 4)
					harl.complain(levels[i++]);
				break;
			case 2:
				while(i < 4)
					harl.complain(levels[i++]);
				break;
			case 3:
				while(i < 4)
					harl.complain(levels[i++]);
				break;
		}
	}
}