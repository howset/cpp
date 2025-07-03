#pragma once

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string const &name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap	&operator=(DiamondTrap const &copy);

		void	whoAmI(void);
		void	attack(std::string const &target);
};