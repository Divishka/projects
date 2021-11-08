#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << this->getName() << " IM ALIVE." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " IM DEAD." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << this->getName() << " IM ALIVE." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	*this = copy;
	std::cout << this->getName() << " WHO ARE YOU." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->getName() << " have enterred in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
	std::cout << this->getName() << " INSANELY SHOOTING AT " << target <<  " with " << this->getDamage() << " damage" <<std::endl;
}

ScavTrap& ScavTrap::operator= (ScavTrap const &copy)
{
	ClapTrap::operator=(copy);
	return (*this);
}
