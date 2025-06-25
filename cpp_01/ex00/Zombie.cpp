#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	//std::cout << "Zombie created." << std::endl;
	this->name = name;
	std::cout << "Zombie " << this->name << " created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}