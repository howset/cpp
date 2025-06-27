/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 11:23:31 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
main as test
*/
int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	//pay attention to the syntax (& and *)!!!
	std::cout << "### Memory address ###########" << std::endl;
	std::cout << "str : " << &string << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;

	//pay attention to the syntax (& and *)!!!
	std::cout << "### Value ####################" << std::endl;
	std::cout << "str : " << string << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << std::endl;
	return (0);
}