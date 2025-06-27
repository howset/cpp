/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:01:18 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/06/27 15:17:46 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
main as test
pay attention to the syntax (& and *)!!!
*/
int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::string string2 = string;

	std::cout << "### Memory address ###" << std::endl;
	std::cout << "string : " << &string << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;
	std::cout << "string2 : " << &string2 << std::endl;
	std::cout << std::endl;

	std::cout << "### Value ###" << std::endl;
	std::cout << "string : " << string << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << "string2 : " << string2 << std::endl;
	std::cout << std::endl;

	std::cout << "##### Change string #####" << std::endl;
	string = "That is NOT Brain";

	std::cout << "### Memory address ###" << std::endl;
	std::cout << "string : " << &string << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;
	std::cout << "string2 : " << &string2 << std::endl;
	std::cout << std::endl;

	std::cout << "### Value ###" << std::endl;
	std::cout << "string : " << string << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	std::cout << "string2 : " << string2 << std::endl;
	std::cout << std::endl;

	return (0);
}