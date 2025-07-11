/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetya <hsetya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:01:57 by hsetya            #+#    #+#             */
/*   Updated: 2025/07/11 23:01:58 by hsetya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib> //rand(), srand()
#include <ctime> //time()

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{
	setupSeed(); //setup randomness once for execute
	std::cout << GRE << "RRForm " << this->getName() << " constructed." << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	setupSeed(); //setup randomness once for execute
	std::cout << GRE << "RRForm " << this->getName() << " constructed." << RES << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GRE << "RRForm " << this->getName() << " destructed." << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm::AForm(copy), _target(copy._target)
{
	std::cout << GRE << "Copy constructor called." << RES << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << GRE << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == true)
	{
		if (executor.getGrade() <= this->getGrdExec())
		{
			if (rand() % 2 == 0)
				std::cout << GRE << this->_target << " has been robotomized successfully!" << RES << std::endl;
			else
				std::cout << GRE << "Robotomy of " << this->_target << " failed!" << RES << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		std::cout << GRE << this->_target << " cant be robotomized." << RES << std::endl;
}

void	RobotomyRequestForm::setupSeed()
{
	static bool seed_setup = false;
	if (!seed_setup)
	{
		srand(time(NULL));
		seed_setup = true;
	}
}