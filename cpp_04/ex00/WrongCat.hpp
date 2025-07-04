#pragma once

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		~WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat	&operator=(const WrongCat &copy);

		void				makeSound() const;
};
