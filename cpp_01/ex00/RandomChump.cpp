#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie z(name); //on stack, destroyed at function end
	z.announce();
}