/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsetyamu <hsetyamu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:07:12 by hsetyamu          #+#    #+#             */
/*   Updated: 2025/07/07 13:07:13 by hsetyamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		Cat(const Cat &copy);
		Cat	&operator=(const Cat &copy);

		void				makeSound() const;
};
