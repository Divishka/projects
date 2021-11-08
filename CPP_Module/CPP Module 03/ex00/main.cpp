#include "ClapTrap.hpp"

#include <iostream>
#include <string>

int main( void )
{
	ClapTrap Random;
	ClapTrap Carl("Carl");
	ClapTrap Carl_2;
	Carl_2 = Carl;
	ClapTrap Carl_3(Carl_2);

	std::cout << std::endl;


	Random.attack("ME");
	Random.takeDamage(79);
	Random.beRepaired(69);

	std::cout << std::endl;

	Carl.attack("YOU");
	Carl.takeDamage(36);
	Carl.beRepaired(64);

	std::cout << std::endl;

	Carl_2.attack("THEM");
	Carl_2.takeDamage(94);
	Carl_2.beRepaired(273);

	std::cout << std::endl;

	Carl_3.attack("US");
	Carl_3.takeDamage(3);
	Carl_3.beRepaired(570);

	std::cout << std::endl;

	return 0;
}