/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:29:43 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/14 14:29:59 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
Best Practice Guidelines:
Always Use Initializer Lists For:
- Const members
- Reference members  
- Base classes
- Member objects without default constructors
Prefer Initializer Lists For:
- All other members (consistency and performance)
- When no complex logic needed
Body Assignment OK for:
- Complex initialization requiring validation
- Conditional initialization logic
- When value has to be computed first

**Rule of Thumb:** Use initializer lists whenever possible, use body assignment
only when you need the flexibility of procedural logic.
*/
Bureaucrat::Bureaucrat(): _name("default"), _grade(42)
{
	std::cout << CYA << "Bureaucrat " << this->_name << " constructed." << RES << std::endl;
}

/*
Member Initialization List
- Members are directly constructed with the provided values
- Happens before the constructor body executes
- Single step: construct with final value

Body Assignment
- Members are default constructed first
- Then assigned new values in the constructor body
- Two steps: default construct + assign
*/
Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade < GRADE_MAX)
		throw (Bureaucrat::GradeTooHighException());
	else if (this->_grade > GRADE_MIN)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << CYA << "Bureaucrat " << this->_name << " constructed." << RES << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << CYA << "Bureaucrat " << this->_name << " destructed." << RES << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << CYA << "Copy constructor called." << RES << std::endl;
	//*this = copy; //this can't assign to const _name, so use member initialization list
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