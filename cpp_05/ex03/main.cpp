/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2026/01/08 16:18:12 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

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
	/* std::cout << "#########################################" << std::endl;
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
	catch (std::exception &e)
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
	catch (std::exception &e)
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
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "#########################################" << std::endl;
	std::cout << "#########################################" << std::endl;
	try
		{
			Bureaucrat Cow("CowCow", 24);
			AForm AForm("42X", 25, 45);
			std::cout << Cow << std::endl;
			std::cout << AForm << std::endl;
			Cow.signForm(AForm);
			std::cout << AForm << std::endl;
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
			AForm AForm("42Y", 25, 45);
			std::cout << Horse << std::endl;
			std::cout << AForm << std::endl;
			Horse.signForm(AForm);
			std::cout << AForm << std::endl;
		}
	catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		} */

	/* std::cout << "#########################################" << std::endl;
	std::cout << "# Presidential Pardon ###################" << std::endl;
	std::cout << "#########################################" << std::endl;
	try
	{
		Bureaucrat signer("PigPig", 20);
		Bureaucrat execer("FrogFrog", 1);
		PresidentialPardonForm pardon("FoxFox");

		std::cout << std::endl;
		std::cout << "-- Status --" << std::endl;
		std::cout << signer << std::endl;
		std::cout << execer << std::endl;
		std::cout << pardon << std::endl;

		std::cout << std::endl;
		std::cout << "-- Form signing --" << std::endl;
		signer.signForm(pardon);
		std::cout << pardon << std::endl;

		std::cout << std::endl;
		std::cout << "-- Form signing again --" << std::endl;
		signer.signForm(pardon);
		std::cout << pardon << std::endl;

		std::cout << std::endl;
		std::cout << "-- Execute --" << std::endl;
		//pardon.execute(execer);
		execer.executeForm(pardon);

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "#########################################" << std::endl;
	std::cout << "# Robotomy Request ######################" << std::endl;
	std::cout << "#########################################" << std::endl;
	try
	{
		Bureaucrat signer("PigPig", 73);
		Bureaucrat execer("FrogFrog", 40);
		RobotomyRequestForm request("FoxFox");

		std::cout << std::endl;
		std::cout << "-- Status --" << std::endl;
		std::cout << signer << std::endl;
		std::cout << execer << std::endl;
		std::cout << request << std::endl;

		std::cout << std::endl;
		std::cout << "-- Form signing --" << std::endl;
		signer.signForm(request);
		std::cout << request << std::endl;

		std::cout << std::endl;
		std::cout << "-- Increment signer grade --" << std::endl;
		signer.increGrade();
		signer.signForm(request);
		std::cout << request << std::endl;

		std::cout << std::endl;
		std::cout << "-- Execute --" << std::endl;
		for (int i = 0; i <= 10; i++)
			//request.execute(execer);
			execer.executeForm(request);

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "#########################################" << std::endl;
	std::cout << "# Shrubbery Creation ####################" << std::endl;
	std::cout << "#########################################" << std::endl;
	try
	{
		Bureaucrat signer("PigPig", 140);
		Bureaucrat execer("FrogFrog", 138);
		ShrubberyCreationForm creation("Garden");

		std::cout << std::endl;
		std::cout << "-- Status --" << std::endl;
		std::cout << signer << std::endl;
		std::cout << execer << std::endl;
		std::cout << creation << std::endl;

		std::cout << std::endl;
		std::cout << "-- Form signing --" << std::endl;
		signer.signForm(creation);
		std::cout << creation << std::endl;

//		std::cout << std::endl;
//		std::cout << "-- Execute --" << std::endl;
//		request.execute(execer);

		std::cout << std::endl;
		std::cout << "-- Increment executor grade --" << std::endl;
		execer.increGrade();
		std::cout << execer << std::endl;

		std::cout << std::endl;
		std::cout << "-- Execute again --" << std::endl;
		//creation.execute(execer);
		execer.executeForm(creation);

		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	} */

	std::cout << "#########################################" << std::endl;
	std::cout << "# Intern ################################" << std::endl;
	std::cout << "#########################################" << std::endl;
	std::cout << "#########################################" << std::endl;

	try
	{
		Intern intern;
		Bureaucrat signer("Boss", 1);
		Bureaucrat executor("Worker", 1);

		std::cout << std::endl;
		std::cout << "-- Shrubbery form --" << std::endl;
		AForm* shrub = intern.makeForm("shrubbery creation", "home");
		std::cout << *shrub << std::endl;
		signer.signForm(*shrub);
		//shrub->execute(executor);
		executor.executeForm(*shrub); //must dereference
		delete shrub;
		
		std::cout << std::endl;
		std::cout << "-- Robotomy form --" << std::endl;
		AForm* robot = intern.makeForm("robotomy request", "Howard");
		std::cout << *robot << std::endl;
		signer.signForm(*robot);
		//robot->execute(executor);
		executor.executeForm(*robot);
		delete robot;
		
		std::cout << std::endl;
		std::cout << "-- Presidential form --" << std::endl;
		AForm* pardon = intern.makeForm("presidential pardon", "Howard");
		std::cout << *pardon << std::endl;
		signer.signForm(*pardon);
		//pardon->execute(executor);
		executor.executeForm(*pardon);
		delete pardon;
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
