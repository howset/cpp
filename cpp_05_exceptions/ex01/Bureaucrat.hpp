/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:29:17 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/14 14:43:21 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

#define RES	"\033[0m"
#define RED	"\033[31m"
#define GRE	"\033[32m"
#define YEL	"\033[33m"
#define BLU	"\033[34m"
#define MAG	"\033[35m"
#define CYA	"\033[36m"
#define WHI	"\033[37m"

#define GRADE_MAX 1
#define GRADE_MIN 150

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator=(const Bureaucrat &copy);

		std::string	const	&getName() const;
		int			const	&getGrade() const;
		void				setGrade(int grade);

		void				increGrade();
		void				decreGrade();
		void				signForm(Form &form);

		//this classinherits from std::exception.
		//overrides the virtual what() method
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

std::ostream	&operator<<(std::ostream &str, const Bureaucrat &bureaucrat);