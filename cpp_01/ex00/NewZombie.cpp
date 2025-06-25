#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombie;
	
	zombie = new Zombie(name); //on heap, must be deleted
	return (zombie);
}