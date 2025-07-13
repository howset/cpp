#pragma once

# include "AForm.hpp"

enum FormType
{
	SHRUBBERY_CREATION,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON
};
class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &copy);

		AForm	*makeForm(const std::string &form_name, const std::string &target);
		int		retFormType(const std::string &formName);

		class FormErrorException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};