#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	hp = 100;
	ep = 100;
	damage = 30;
	std::cout << this->getName() << " has been created. SCAVIBOI HERE" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << " has been destroyed. Sacviboy not here anymore :(" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hp = 100;
	ep = 100;
	damage = 30;
	std::cout << this->getName() << " has been created. AGAIN ME!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	*this = copy;
	std::cout << this->getName() << " has been copied. Ah WHo are yoU.?" << std::endl;
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
