/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:29:15 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/09 19:29:16 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(42) //??
{
	std::cout << CYA << "Bureaucrat " << this->_name << " constructed." << RES << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) //??
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << CYA << "Bureaucrat " << this->_name << " constructed." << RES << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYA << "Bureaucrat " << this->_name << " destructed." << RES << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << CYA << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << CYA << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_grade = copy._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	const	&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

void	Bureaucrat::increGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}
void	Bureaucrat::decreGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
	{
		std::cout << form.getName() << ", is already signed\n";
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << CYA << this->_name << " signed " << form.getName() << RES << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << CYA << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << RES << std::endl;
	}
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (CYA "Grade too high" RES);
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (CYA "Grade too low" RES);
}

std::ostream	&operator<<(std::ostream &str, const Bureaucrat &bureaucrat)
{
	str << CYA
		<< bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< "."
		<< RES;
	return (str);
}