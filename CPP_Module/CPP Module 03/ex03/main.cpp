#include "DiamondTrap.hpp"

#include <iostream>
#include <string>

int main( void )
{
	DiamondTrap Monster("Monster");

	std::cout << std::endl;

	Monster.attack("THEM");
	std::cout << "My name is " << Monster.getName() << " or... maybe " << Monster.ClapTrap::getName() << std::endl;
	Monster.takeDamage(94);
	std::cout << Monster.getHP() << std::endl;
	Monster.beRepaired(273);
	std::cout << Monster.getHP() << std::endl;
	Monster.guardGate();
	Monster.highFivesGuys();
	Monster.whoAmI();

	std::cout << std::endl;

	return 0;
}