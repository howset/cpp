/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:29:21 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/11 16:11:23 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <iostream>

//class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grd_sign;
		const int			_grd_exec;
	public:
		AForm();
		AForm(std::string const &name, const int &grd_sign, const int &grd_exec);
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm	&operator=(const AForm &copy);

		std::string const	&getName(void) const;
		bool const			&getSigned(void) const;
		int const			&getGrdSign(void) const;
		int const			&getGrdExec(void) const;

		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0; //this one virtual because derived classes must implement

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

std::ostream &operator<<(std::ostream &str, const AForm &AForm);