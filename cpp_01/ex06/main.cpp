/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 11:56:04 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
key: https://cplusplus.com/doc/tutorial/control/
break statements are needed after each group of statements for a particular label. 
If break is not included, all statements following the case (including those under any other labels) are also executed,
until the end of the switch block or a jump statement (such as break) is reached.
*/
int	main(int argc, char *argv[])
{
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;
	std::string level;

	if (argc != 2)
	{
		std::cout << "Unrecognized complaint" << std::endl;
		return (1);
	}
	else
	{
		level = argv[1];
		for (size_t i = 0; i < level.length(); ++i) 
			level[i] = toupper(level[i]);
		for (i = 0; i < 4; i++)
		{
			if (level == levels[i])
				break;
		}
		switch (i)
		{
			case 0:
				harl.complain(levels[0]);
			case 1:
				harl.complain(levels[1]);
			case 2:
				harl.complain(levels[2]);
			case 3:
				harl.complain(levels[3]);
				break;
			default:
				std::cout << "Unrecognized complaint" << std::endl;
		}
	}
}