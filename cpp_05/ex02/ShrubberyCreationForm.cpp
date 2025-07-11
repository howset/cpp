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

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

}