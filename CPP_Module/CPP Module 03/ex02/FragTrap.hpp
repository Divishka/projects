#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {

public:

	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &copy);
	~FragTrap();
	FragTrap& operator= (FragTrap const &copy);

	void attack(std::string const& target);
	void highFivesGuys(void);

};




#endif