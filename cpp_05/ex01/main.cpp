/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/14 14:48:23 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

/*
Exception handling is a mechanism to handle runtime errors instead of
crashing the program. It uses three keywords: throw, try, and catch.
- throw is used to raise (throw) an exception when an error occurs.
	- Normal execution stops immediately
	- Program looks for a matching catch block
	- If no catch block found, program terminates
- try defines a block of code that might throw exceptions (protected code block)
	- Code inside try block executes normally
	- If exception is thrown, execution jumps to matching catch block
	- Code after the throw point doesn't execute
- catch defines how to handle specific types of exceptions (handler)
	- Catches any exception that inherits from std::exception
	- e.what() returns the error message
	- Program continues after the catch block
*/
int	main(void)
{
	std::cout << "#########################################" << std::endl;
	std::cout << "# Higher grade ##########################" << std::endl;
	std::cout << "Name: DogDog" << std::endl;
	std::cout << "Grade: 0" << std::endl;
	try
	{
		Bureaucrat dog("DogDog", 0);
		std::cout << dog << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "# Lower grade ###########################" << std::endl;
	std::cout << "Name: CatCat" << std::endl;
	std::cout << "Grade: 151" << std::endl;
	try
	{
		Bureaucrat cat("CatCat", 151);
		std::cout << cat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "# Decrement grade #######################" << std::endl;
	std::cout << "Name: FrogFrog" << std::endl;
	std::cout << "Grade: 148, decrement by 1" << std::endl;
	Bureaucrat *frog = new Bureaucrat("FrogFrog", 148);
	try
	{
		for (int i = 0; i < 4; i++)
		{
			frog->decreGrade();
			std::cout << *frog << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete frog;
	std::cout << "#########################################" << std::endl;
	std::cout << "# Increment grade, heap #################" << std::endl;
	std::cout << "Name: PigPig" << std::endl;
	std::cout << "Grade: 3, increment by 1" << std::endl;
	Bureaucrat *pig = new Bureaucrat("PigPig", 3);
	try
	{
		for (int i = 0; i < 4; i++)
		{
			pig->increGrade();
			std::cout << *pig << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete pig;
	std::cout << "#########################################" << std::endl;
	std::cout << "# Increment grade, stack ################" << std::endl;
	std::cout << "Name: PigPig" << std::endl;
	std::cout << "Grade: 3, increment by 1" << std::endl;
	try
	{
		Bureaucrat pig("PigPig", 3);
		for (int i = 0; i < 4; i++)
		{
			pig.increGrade();
			std::cout << pig << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "# Signing success #######################" << std::endl;
	try
	{
		Bureaucrat Cow("CowCow", 24);
		Form Form("42X", 25, 45);
		std::cout << Cow << std::endl;
		std::cout << Form << std::endl;
		Cow.signForm(Form);
		std::cout << Form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "# Signing fail ##########################" << std::endl;
	try
	{
		Bureaucrat Horse("HorseHorse", 26);
		Form Form("42Y", 25, 45);
		std::cout << Horse << std::endl;
		std::cout << Form << std::endl;
		Horse.signForm(Form);
		std::cout << Form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
