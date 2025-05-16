#include "Zombie.hpp"

int main()
{
	Zombie *zombie = newZombie("Gecko");

	zombie->announce();
	delete zombie;
	//randomChump("salam");
	return (0);
}