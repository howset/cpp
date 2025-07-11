#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &copy);

		void execute(Bureaucrat const &executor) const;
};
