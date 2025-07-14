#include "Intern2.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* Intern::createShrubberyForm(const std::string &target)
{
	std::cout << BLU << "Intern creates shrubbery creation" << RES << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomyForm(const std::string &target)
{
	std::cout << BLU << "Intern creates robotomy request" << RES << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidentialForm(const std::string &target)
{
	std::cout << BLU << "Intern creates presidential pardon" << RES << std::endl;
	return (new PresidentialPardonForm(target));
}

Intern::Intern()
{
	std::cout << BLU << "Intern Default constructed." << RES << std::endl;
}

Intern::~Intern()
{
	std::cout << BLU << "Intern Default destructed." << RES << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << BLU << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << BLU << "Copy assignment operator called." << RES << std::endl;
	//if (this != &copy) //best practice to check for self-assignment
		//this->_grade = copy._grade;
	(void) copy;
	return (*this);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formNames[3] = {"shrubbery creation",
								"robotomy request", 
								"presidential pardon"};
	AForm* (Intern::*formCreators[3])(const std::string&) = {&Intern::createShrubberyForm,
															&Intern::createRobotomyForm,
															&Intern::createPresidentialForm};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			return (this->*formCreators[i])(target);
	}
	std::cout << BLU << "Cannot create: " << formName << "." << RES << std::endl;
	throw Intern::FormErrorException();
}
char const	*Intern::FormErrorException::what(void) const throw()
{
	return (BLU "Cannot create form" RES);
}