/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/11 16:02:14 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

/*
Exception handling is a mechanism to handle runtime errors gracefully instead of
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
	std::cout << "Name: DogDog" << std::endl;
	std::cout << "Grade: 0" << std::endl;
	try
	{
		Bureaucrat Dog("DogDog", 0);
		std::cout << Dog << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "Name: CatCat" << std::endl;
	std::cout << "Grade: 151" << std::endl;
	try
	{
		Bureaucrat Cat("CatCat", 151);
		std::cout << Cat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "Name: FrogFrog" << std::endl;
	std::cout << "Grade: 148, decrement by 1" << std::endl;
	Bureaucrat *Frog = new Bureaucrat("FrogFrog", 148);
	try
	{
		for (int i = 0; i < 4; i++)
		{
			Frog->decreGrade();
			std::cout << *Frog << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete Frog;
	std::cout << "#########################################" << std::endl;
	std::cout << "Name: PigPig" << std::endl;
	std::cout << "Grade: 3, increment by 1" << std::endl;
	Bureaucrat *Pig = new Bureaucrat("PigPig", 3);
	try
	{
		for (int i = 0; i < 4; i++)
		{
			Pig->increGrade();
			std::cout << *Pig << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete Pig;
	std::cout << "#########################################" << std::endl;
	std::cout << "Name: PigPig" << std::endl;
	std::cout << "Grade: 3, increment by 1" << std::endl;
	try
	{
		Bureaucrat Pig("PigPig", 3);
		for (int i = 0; i < 4; i++)
		{
			Pig.increGrade();
			std::cout << Pig << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "#########################################" << std::endl;
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
	std::cout << "#########################################" << std::endl;
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
