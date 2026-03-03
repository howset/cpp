/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:10:32 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 15:57:33 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "DEBUG 1" << std::endl;
	std::cout << "I love blablabla" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "INFO 2" << std::endl;
	std::cout << "I cannot blablabla" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "WARNING 3" << std::endl;
	std::cout << "I think blablabla" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "ERROR 4" << std::endl;
	std::cout << "This is blablabla" << std::endl;
}

void	Harl::complain(std::string level)
{
	//arr of memb func ptrs, tricky syntax
	void			(Harl::*compl_ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int				flag = -1;

	for (size_t i = 0; i < level.length(); ++i)
		level[i] = toupper(level[i]);
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			flag = i;
			break ;
		}
	}
	if (flag != -1)
		(this->*compl_ptr[flag])();
	else
		std::cout << "Unrecognized complaint" << std::endl;
}