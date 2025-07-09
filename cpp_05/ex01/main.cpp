/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:23:27 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/09 19:21:53 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

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
			Bureaucrat Cow("CowCow", 15);
			Form Form("42X", 20, 45);
			std::cout << Cow << std::endl;
			std::cout << Form << std::endl;
			Cow.signForm(Form);
			std::cout << Form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	std::cout << std::endl;
	return 0;
}
