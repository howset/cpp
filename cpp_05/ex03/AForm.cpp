/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:09:40 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/14 14:45:47 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(false), _grd_sign(0), _grd_exec(0)
{
	std::cout << MAG << "AForm " << this->_name << " constructed." << RES << std::endl;
}

AForm::AForm(const std::string &name, const int &grd_sign, const int &grd_exec): _name(name), _signed(0), _grd_sign(grd_sign), _grd_exec(grd_exec)
{
	if (grd_sign < FGRADE_MAX || grd_exec < FGRADE_MAX)
		throw AForm::GradeTooHighException();
	else if (grd_sign > FGRADE_MIN || grd_exec > FGRADE_MIN)
		throw AForm::GradeTooLowException();
	std::cout << MAG << "AForm " << this->_name << " constructed." << RES << std::endl;
}

AForm::~AForm()
{
	std::cout << MAG << "AForm " << this->_name << " destructed." << RES << std::endl;
}

AForm::AForm(const AForm &copy): _name(copy._name), _signed(copy._signed), _grd_sign(copy._grd_sign), _grd_exec(copy._grd_exec)
{
	std::cout << MAG << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << MAG << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_signed = copy._signed;
	return (*this);
}

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

bool const	&AForm::getSigned(void) const
{
	return (this->_signed);
}

int const	&AForm::getGrdSign(void) const
{
	return (this->_grd_sign);
}

int const	&AForm::getGrdExec(void) const
{
	return (this->_grd_exec);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grd_sign)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_signed = 1;
		std::cout << MAG << bureaucrat.getName() << " successfully signed " << this->_name << RES << std::endl;
	}
}

char const	*AForm::GradeTooHighException::what(void) const throw()
{
	return (MAG "Grade too high" RES);
}

char const	*AForm::GradeTooLowException::what(void) const throw()
{
	return (MAG "Grade too low" RES);
}

std::ostream	&operator<<(std::ostream &str, AForm const &AForm)
{
	str << MAG
		<< "AForm " << AForm.getName()
		<< ", sign grade " << AForm.getGrdSign()
		<< ", exec grade " << AForm.getGrdExec()
		<< ", signed: " << (AForm.getSigned() ? "yes" : "no")
		<< RES;
	return (str);
}