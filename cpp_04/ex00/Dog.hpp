/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:19 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 13:07:20 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog(std::string type);
		~Dog();
		Dog(const Dog &copy);
		Dog	&operator=(const Dog &copy);

		void				makeSound() const;
};
