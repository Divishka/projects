#include "HumanB.hpp"

HumanB::HumanB() { }

HumanB::HumanB(std::string name)
{ 
    m_name = name;
    m_weapon = 0; //was nullptr
}

HumanB::~HumanB() { }

void    HumanB::attack()
{ 
    if (m_weapon != nullptr)
        std::cout << m_name << "  attacks with his " << m_weapon->getType() << std::endl;
    else
        std::cout << m_name << "  i have no weapon! fck you!!!" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    m_weapon = &weapon;
}

