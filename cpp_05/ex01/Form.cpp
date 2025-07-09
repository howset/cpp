#include "Form.hpp"

Form::Form(): _name("default"), _signed(false), _grd_sign(0), _grd_exec(0)//??
{
	std::cout << MAG << "Form " << this->_name << " constructed." << RES << std::endl;
}

Form::Form(const std::string &name, const int &grd_sign, const int &grd_exec): _name(name), _signed(0), _grd_sign(grd_sign), _grd_exec(grd_exec)
{
	if (grd_sign < 1 || grd_exec < 1)
		throw Form::GradeTooHighException();
	else if (grd_sign > 150 || grd_exec > 150)
		throw Form::GradeTooLowException();
	std::cout << MAG << "Form " << this->_name << " constructed." << RES << std::endl;
}

Form::~Form()
{
	std::cout << MAG << "Form " << this->_name << " destructed." << RES << std::endl;
}

Form::Form(const Form &copy): _name(copy._name), _signed(copy._signed), _grd_sign(copy._grd_sign), _grd_exec(copy._grd_exec)
{
	std::cout << MAG << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << MAG << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_signed = copy._signed;
	return (*this);
}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

bool const	&Form::getSigned(void) const
{
	return (this->_signed);
}

int const	&Form::getGrdSign(void) const
{
	return (this->_grd_sign);
}

int const	&Form::getGrdExec(void) const
{
	return (this->_grd_exec);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grd_exec)
		throw (Form::GradeTooLowException());
	else
	{
		this->_signed = 1;
		std::cout << MAG << bureaucrat.getName() << " successfully signed " << this->_name << RES << std::endl;
	}
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return (MAG "Grade too high" RES);
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return (MAG "Grade too low" RES);
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	str << MAG
		<< "Form " << form.getName()
		<< ", sign grade " << form.getGrdSign()
		<< ", exec grade " << form.getGrdExec()
		<< ", signed: " << (form.getSigned() ? "yes" : "no")
		<< RES;
	return (str);
}