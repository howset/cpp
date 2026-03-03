#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << GRE << "DiamondTrap Default constructed." << RES << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	std::cout << GRE << "DiamondTrap " << this->getName() << " constructed." << RES << std::endl;
	// this->setHp(FragTrap::getHp()); //inherit attack from frag
	// this->setEp(ScavTrap::getEp()); //inherit attack from scav
	// this->setAd(FragTrap::getAd()); //inherit attack from frag
	
	// this->_hp = FragTrap::_hp;
	// this->_ep = ScavTrap::_ep;
	// this->_ad = FragTrap::_ad;

	//this->_hp = 100; //direct initialization _hp from fragtrap
	//this->_ep = 50; //direct initialization _ep from scavtrap
	//this->_ad = 30;

	FragTrap fragTemp("temp");
	ScavTrap scavTemp("temp");

	this->_hp = fragTemp.getHp();
	this->_ep = scavTemp.getEp();
	this->_ad = fragTemp.getAd();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << GRE << "DiamondTrap " << this->getName() << " destructed." << RES << std::endl;
}

//DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy) //doesnt properly handle diamond inheritance
DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
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