
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

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		~WrongAnimal(); //virtual
		WrongAnimal(const WrongAnimal &copy); //copy constr
		WrongAnimal	&operator=(const WrongAnimal &copy); //assignment operator

		void		makeSound() const;

		std::string const	&getType() const;
		void				setType(std::string type);
};
