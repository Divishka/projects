#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>
#include <string>

int main( void )
{
	FragTrap Random;
	FragTrap Carl("Carl");
	FragTrap Carl_2;
	Carl_2 = Carl;
	FragTrap Carl_3(Carl_2);

	std::cout << std::endl;


	Random.attack("ME");
	Random.takeDamage(79);
	Random.beRepaired(69);
	Random.highFivesGuys();

	std::cout << std::endl;

	Carl.attack("YOU");
	Carl.takeDamage(36);
	Carl.beRepaired(64);
	Carl.highFivesGuys();

	std::cout << std::endl;

	Carl_2.attack("THEM");
	Carl_2.takeDamage(94);
	Carl_2.beRepaired(273);
	Carl_2.highFivesGuys();

	std::cout << std::endl;

	Carl_3.attack("US");
	Carl_3.takeDamage(3);
	Carl_3.beRepaired(570);
	Carl_3.highFivesGuys();
	Carl_3.takeDamage(570);
	std::cout << Carl_3.getHP() << std::endl;

	std::cout << std::endl;

	return 0;
}