
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << RED << "WrongAnimal Default constructed." << RES << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << RED << "WrongAnimal " << this->_type << " constructed." << RES << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal " << this->_type << " destructed." << RES << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << RED << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << RED << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_type = copy._type;
	return (*this);
}

std::string const	&WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << RED << "WrongAnimal " << this->_type << " says AAAARGH!." << RES << std::endl;
}