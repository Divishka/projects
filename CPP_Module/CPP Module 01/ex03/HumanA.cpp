#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): m_weapon(weapon)
{
    m_name = name;
}

HumanA::~HumanA() { }

void    HumanA::attack()
{
	std::cout << m_name << "  attacks with his " << m_weapon.getType() << std::endl;
}
