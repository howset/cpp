/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetya <hsetya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:02:04 by hsetya            #+#    #+#             */
/*   Updated: 2025/07/11 23:02:05 by hsetya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null")
{
	std::cout << RED << "SCForm " << this->getName() << " constructed." << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << RED << "SCForm " << this->getName() << " constructed." << RES << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "SCForm " << this->getName() << " destructed." << RES << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm::AForm(copy), _target(copy._target)
{
	std::cout << RED << "Copy constructor called." << RES << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << RED << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == true)
	{
		if (executor.getGrade() <= this->getGrdExec())
		{
			plantShrub();
			std::cout << RED << executor.getName() << " planted shrubbery at " << this->_target << RES << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	else
		std::cout << RED << "Shrubbery cant be planted." << RES << std::endl;
}

void	ShrubberyCreationForm::plantShrub() const
{
	std::ofstream	out;

	out.open((this->_target + "_shrubbery").c_str());
	if (!out.is_open())
		throw std::runtime_error(RED "Error creating file" RES);
	out <<	"     _                _     _                     \n"
		"    | |              | |   | |                    \n"
		" ___| |__  _ __ _   _| |__ | |__   ___ _ __ _   _ \n"
		"/ __| '_ \\| '__| | | | '_ \\| '_ \\ / _ \\ '__| | | |\n"
		"\\__ \\ | | | |  | |_| | |_) | |_) |  __/ |  | |_| |\n"
		"|___/_| |_|_|   \\__,_|_.__/|_.__/ \\___|_|   \\__, |\n"
		"                                             __/ |\n"
		"                                            |___/ \n";
	out.close();
}