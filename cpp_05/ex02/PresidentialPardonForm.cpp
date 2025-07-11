#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{
	std::cout << YEL << "PPForm " << this->getName() << " constructed." << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << YEL << "PPForm " << this->getName() << " constructed." << RES << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << YEL << "PPForm " << this->getName() << " destructed." << RES << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm::AForm(copy), _target(copy._target)
{
	std::cout << YEL << "Copy constructor called." << RES << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << YEL << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == true)
	{
		if (executor.getGrade() < this->getGrdExec())
			std::cout << YEL << this->_target << " has been pardoned by Zaphod Beeblebrox." << RES << std::endl;
		else
			throw AForm::GradeTooLowException(); //set grade as 6 in main. Bureaucrat also works, but this is a form check, not bureaucrat.
	}
	else
		std::cout << YEL << this->_target << " cant be pardoned." << RES << std::endl;
		//throw std::runtime_error(YEL"Form must be signed before execution." RES); //throw standard exception. Flow: exception thrown, stack unwinding (objs detroyed), catch/handle exception
}