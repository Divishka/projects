#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	
private:

	std::string		Name;
	unsigned int	hp;
	unsigned int	ep;
	unsigned int	damage;
	

public:

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap const &copy);
	~ClapTrap();

	ClapTrap& operator= (ClapTrap const &copy);
};

#endif