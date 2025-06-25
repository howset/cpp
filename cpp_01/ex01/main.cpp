/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/25 18:06:42 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string intToString(int num)
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

int main()
{
	Zombie	*zombie;
	int		num;
	std::string	idxName;
	std::string zomName;

	num = 10;
	zombie = zombieHorde(num, "");
	for (int i = 0; i < num; i++)
	{
		idxName = "Gecko" + intToString(i);
		zombie[i].setName(idxName);
		zomName = zombie[i].getName();
		std::cout << "Set name: " << zomName << "." << std::endl;
	}
	for (int i = 0; i < num; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}