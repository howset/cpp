#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << GRE << "DiamondTrap Default constructed." << RES << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	std::cout << GRE << "DiamondTrap " << this->getName() << " constructed." << RES << std::endl;
	this->setHp(FragTrap::getHp()); //inherit attack from frag
	this->setEp(ScavTrap::getEp()); //inherit attack from scav
	this->setAd(FragTrap::getAd()); //inherit attack from frag
}

DiamondTrap::~DiamondTrap()
{
	std::cout << GRE << "DiamondTrap " << this->getName() << " destructed." << RES << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	std::cout << GRE << "DiamondTrap copy constructor called." << RES << std::endl;
	*this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << GRE << "DiamondTrap copy assignment operator called." << RES << std::endl;
	if (this != &copy)
	{
		ClapTrap::operator=(copy); //call base class assignment
		this->_name = copy._name;
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target); //inherit attack from scav
}

/*
2 different names associated with the same obj.
*/
void DiamondTrap::whoAmI()
{
	std::cout << GRE << "DiamondTrap name: " << this->_name << "." << RES << std::endl;
	std::cout << GRE << "ClapTrap name: " << ClapTrap::getName() << "." << RES << std::endl;
}