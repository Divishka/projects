#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	this->setEP(100);
	this->setDamage(30);
	std::cout << this->getName() << " has been created.^^^^^^^^^^^$####......... Hi? ^_^" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->getName() << " has been destroyed. CRACKKK*#%&#%(Y#" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setEP(100);
	this->setDamage(30);
	std::cout << this->getName() << " has been created.^^^^^^^^^^^$####......... Hi? ^_^" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	*this = copy;
	std::cout << this->getName() << " has been copied.^^^^^^^^^^^$####......... oMGGggg? >_>" << std::endl;
}

void FragTrap::attack(std::string const& target)
{
	std::cout << "Clapppy AT your " << target << " face and other places >_>" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "GiVe Me HiGhFiVe, Lil piECe oF the S U N" << std::endl;
}

FragTrap& FragTrap::operator= (FragTrap const &copy)
{
	ClapTrap::operator=(copy);
	std::cout << "WHOS DOING IT?! (assignation completed)" << std::endl;
	return (*this);
}
