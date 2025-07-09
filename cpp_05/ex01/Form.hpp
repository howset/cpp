/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:29:21 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/09 19:29:22 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <iostream>

//class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grd_sign;
		const int			_grd_exec;
	public:
		Form();
		Form(std::string const &name, const int &grd_sign, const int &grd_exec);
		~Form();
		Form(const Form &copy);
		Form	&operator=(const Form &copy);

		std::string const	&getName(void) const;
		bool const			&getSigned(void) const;
		int const			&getGrdSign(void) const;
		int const			&getGrdExec(void) const;

		void				beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &str, const Form &form);