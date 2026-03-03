/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:12 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 17:00:49 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		Cat(const Cat &copy);
		Cat	&operator=(const Cat &copy);

		void				makeSound() const;

		Brain				*getBrain() const;
		void				setBrain(Brain *brain);
};
