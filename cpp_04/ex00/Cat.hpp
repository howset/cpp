#pragma once

# include "Animal.hpp"

class	Cat : public Animal //virtual inheritance
{
	public:
		Cat();
		Cat(std::string type);
		~Cat();
		Cat(const Cat &copy);
		Cat	&operator=(const Cat &copy);

		void				makeSound() const;
};
