/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:10:32 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 11:51:56 by hsetyamu         ###   ########.fr       */
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
	void			(Harl::*compl_ptr[4])(void); //arr of memb func ptrs, tricky syntax
	std::string		levels[4];

	compl_ptr[0] = &Harl::debug;
	compl_ptr[1] = &Harl::info;
	compl_ptr[2] = &Harl::warning;
	compl_ptr[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	for (size_t i = 0; i < level.length(); ++i)
		level[i] = toupper(level[i]);
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*compl_ptr[i])();
			break ;
		}
	}
}