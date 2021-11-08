#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>
#include <string>

int main( void )
{
	ScavTrap Random;
	ScavTrap Carl("Carl");
	ScavTrap Carl_2;
	Carl_2 = Carl;
	ScavTrap Carl_3(Carl_2);

	std::cout << std::endl;


	Random.attack("ME");
	Random.takeDamage(79);
	Random.beRepaired(69);
	Random.guardGate();

	std::cout << std::endl;

	Carl.attack("YOU");
	Carl.takeDamage(36);
	Carl.beRepaired(64);
	Carl.guardGate();

	std::cout << std::endl;

	Carl_2.attack("THEM");
	Carl_2.takeDamage(94);
	Carl_2.beRepaired(273);
	Carl_2.guardGate();

	std::cout << std::endl;

	Carl_3.attack("US");
	Carl_3.takeDamage(3);
	Carl_3.beRepaired(570);
	Carl_3.guardGate();

	std::cout << std::endl;


	return 0;
}