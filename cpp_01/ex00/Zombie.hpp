#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
//# include <string>
//# include <cstdlib>

class Zombie
{
	private:
		std::string	name;
	public:
		void		announce();
		Zombie(std::string name);
		~Zombie();
};

Zombie* newZombie( std::string name );
//void randomChump( std::string name );

#endif