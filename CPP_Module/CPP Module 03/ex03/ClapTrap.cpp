#include "ClapTrap.hpp"


/*-------------------C O N S T R U C T O R S--------------------*/

std::string ClapTrap::getName()
{
	return (this->Name);
}

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
	this->hp = 100;
	this->ep = 50;
	this->damage = 20;
	std::cout << this->Name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->Name = Name;
	this->hp = 100;
	this->ep = 50;
	this->damage = 20;
	std::cout << this->Name << " has been created." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	*this = copy;
	std::cout << this->Name << " has been created." << std::endl;
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

void ClapTrap::setName(std::string name)
{
	this->Name = name;
}


void ClapTrap::setHP(unsigned int amount)
{
	this->hp = amount;
}

void ClapTrap::setEP(unsigned int amount)
{
	this->ep = amount;
}

void ClapTrap::setDamage(unsigned int amount)
{
	this->damage = amount;
}

unsigned int ClapTrap::getDamage()
{
	return (this->damage);
}

unsigned int ClapTrap::getHP()
{
	return (this->hp);
}

unsigned int ClapTrap::getEP()
{
	return (this->ep);
}

/*--------------------------------------------------------------*/
