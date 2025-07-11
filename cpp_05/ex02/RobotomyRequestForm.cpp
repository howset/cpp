#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{
	std::cout << GRE << "RRForm " << this->getName() << " constructed." << RES << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
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