/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:10:00 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 14:05:37 by hsetyamu         ###   ########.fr       */
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

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const std::string *arr_of_ideas, int size);
		~Brain(); //virtual
		Brain(const Brain &copy); //copy constr
		Brain	&operator=(const Brain &copy); //assignment operator

		std::string const	&getIdeas(int idx) const;
		void				setIdeas(std::string idea, int idx);
};