/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/01 12:57:13 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	intToString(int num)
{
	std::string res = "";
	if (num == 0)
		return ("0");
	while (num > 0)
	{
		res = char('0' + (num % 10)) + res;
		num /= 10;
	}
	return (res);
}

/*
C++ follows the principle that objects should be destroyed in the reverse order
of their construction. This mimics how a stack works -
 Last In, First Out (LIFO).
*/
int	main()
{
	Zombie	*zombie;
	int		num;
	std::string	idxName;
	std::string zomName;

	//determine number of zombs
	num = 5;

	//allocate the objs once by calling zombieHorde
	//passing num (N) and the name as empty ("")
	zombie = zombieHorde(num, "");

	//change the empty names and use indexes to differentiate
	for (int i = 0; i < num; i++)
	{
		idxName = "Gecko" + intToString(i);
		zombie[i].setName(idxName);
		zomName = zombie[i].getName();
	}

	//make each zomb announce
	for (int i = 0; i < num; i++)
		zombie[i].announce();

	//deallocate
	delete[] zombie;
	return (0);
}