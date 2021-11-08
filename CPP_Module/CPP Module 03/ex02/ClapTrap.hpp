#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	
protected:

	std::string		Name;
	unsigned int	hp;
	unsigned int	ep;
	unsigned int	damage;
	

public:

	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap& operator= (ClapTrap const &copy);
	~ClapTrap();

	void attack(std::string const & target);

	std::string getName();
	unsigned int getDamage();
	unsigned int getHP();
	unsigned int getEP();

	void setHP(unsigned int amount);
	void setEP(unsigned int amount);
	void setDamage(unsigned int amount);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

};

#endif