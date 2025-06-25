#include "Zombie.hpp"

int main()
{
	Zombie *zombie;

	zombie = newZombie("Gecko (heap)");
	zombie->announce();
	delete zombie;
	std::cout << std::endl;
	randomChump("Gecki (stack)");
	return (0);
}