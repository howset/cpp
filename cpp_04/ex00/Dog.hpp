#pragma once

# include "Animal.hpp"

class	Dog : public Animal //virtual inheritance
{
	public:
		Dog();
		Dog(std::string type);
		~Dog();
		Dog(const Dog &copy);
		Dog	&operator=(const Dog &copy);

		void				makeSound() const;
};
