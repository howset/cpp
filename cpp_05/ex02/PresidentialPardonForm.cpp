#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{
	std::cout << BLU << "PPForm " << this->getName() << " constructed." << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << BLU << "PPForm " << this->getName() << " constructed." << RES << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLU << "PPForm " << this->getName() << " destructed." << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm::AForm(copy), _target(copy._target)
{
	std::cout << BLU << "Copy constructor called." << RES << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << BLU << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << BLU << this->_target << " has been pardoned by Zaphod Beeblebrox" << RES << std::endl;
}