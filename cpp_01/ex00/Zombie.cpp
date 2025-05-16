#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie created." << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}