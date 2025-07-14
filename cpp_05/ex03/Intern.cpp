#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

int Intern::retFormType(const std::string &formName)
{
	std::string formNames[3] = {"shrubbery creation", //0
								"robotomy request", //1
								"presidential pardon"}; //2
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			return (i);
	}
	return (-1);
}

//not like the cpp1, break is not necessary because every case returns immediately
AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	int type = retFormType(formName);

	switch (type)
	{
		case SHRUBBERY_CREATION:
			std::cout << BLU << "Intern creates " << formName << RES << std::endl;
			return (new ShrubberyCreationForm(target));
		case ROBOTOMY_REQUEST:
			std::cout << BLU << "Intern creates " << formName << RES << std::endl;
			return (new RobotomyRequestForm(target));
		case PRESIDENTIAL_PARDON:
			std::cout << BLU << "Intern creates " << formName << RES << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cout << BLU << "Cannot create: " << formName << "." << RES << std::endl;
			throw Intern::FormErrorException();
	}
}
char const	*Intern::FormErrorException::what(void) const throw()
{
	return (BLU "Cannot create form" RES);
}