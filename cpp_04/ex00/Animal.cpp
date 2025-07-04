
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << CYA << "Animal Default constructed." << RES << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << CYA << "Animal " << this->_type << " constructed." << RES << std::endl;
}

Animal::~Animal()
{
	std::cout << CYA << "Animal " << this->_type << " destructed." << RES << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << CYA << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << CYA << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_type = copy._type;
	return (*this);
}

std::string const	&Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

void	Animal::makeSound() const
{
	std::cout << CYA << "Animal " << this->_type << " says MWAHAHA." << RES << std::endl;
}