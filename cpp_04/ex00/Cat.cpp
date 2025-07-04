
#include "Cat.hpp"

Cat::Cat()
{
	std::cout << YEL << "Cat Default constructed." << RES << std::endl;
}

Cat::Cat(std::string type)
{
	this->_type = type;
	std::cout << YEL << "Cat " << this->_type << " constructed." << RES << std::endl;
}

Cat::~Cat()
{
	std::cout << YEL << "Cat " << this->_type << " destructed." << RES << std::endl;
}

Cat::Cat(const Cat &copy)
{
	std::cout << YEL << "Copy constructor called." << RES << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << YEL << "Copy assignment operator called." << RES << std::endl;
	if (this != &copy) //best practice to check for self-assignment
		this->_type = copy._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << YEL << "Cat " << this->_type << " says meowmeow." << RES << std::endl;
}