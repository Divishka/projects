#include "ClapTrap.hpp"


/*-------------------C O N S T R U C T O R S--------------------*/

void  ClapTrap::attack(std::string const& target)
{
	this->ep -= 20;
	std::cout << this->Name << " attacked " << target << " with " << this->damage << " damage." << std::endl;
}

void  ClapTrap::takeDamage(unsigned int amount)
{
	this->hp -= amount;
	std::cout << this->Name << " recieved " << amount << " damage." << std::endl;
}

void  ClapTrap::beRepaired(unsigned int amount)
{
	this->hp += amount;
	std::cout << this->Name << " restored " << amount << " HP." << std::endl;
}

ClapTrap::ClapTrap()
{
	this->Name = "Random";
	this->hp = 10;
	this->ep = 10;
	this->damage = 0;
	std::cout << this->Name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->Name = Name;
	this->hp = 10;
	this->ep = 10;
	this->damage = 0;
	std::cout << this->Name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << this->Name << " has been copied." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->Name << " has been destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &copy)
{
	this->Name = copy.Name;
	this->hp = copy.hp;
	this->ep = copy.ep;
	this->damage = copy.damage;
	std::cout << this->Name << " had been assigned." << std::endl;

	return (*this);
}

/*--------------------------------------------------------------*/
