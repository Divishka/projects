#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "Someone created me (DIAMOND default constructor)" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	ClapTrap::setName(name + "_clap_name");
	this->setHP(FragTrap::getHP());
	this->setEP(ScavTrap::getEP());
	this->setDamage(FragTrap::getDamage());
	std::cout << "Creation of the MoNster(?) has been completed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	*this = copy;
	std::cout << "Copied completed for DIAMOND" << std::endl;
}

DiamondTrap& DiamondTrap::operator= (DiamondTrap const &copy)
{
	ClapTrap::operator=(copy);
	std::cout << "assignation for diamond" << std::endl;
	return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "NooOOOoooooo (destructor Diamond)" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "It's name is " << this->getName() << std::endl
	<< "ClapTrap name is " << this->ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName()
{
	return (this->_name);
}

