#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap {

private:

	std::string _name;

public:

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &copy);
	DiamondTrap& operator= (DiamondTrap const &copy);
	~DiamondTrap();

	std::string getName();

	void attack(std::string const &target);
	void whoAmI(void);

};




#endif
