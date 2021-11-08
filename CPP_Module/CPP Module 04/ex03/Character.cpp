#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	// std::cout << "Default character constructor called" << std::endl;
}

std::string  const& Character::getName() const
{
	return (this->name);
}

Character::Character(std::string name)
{
	this->name = name;
	for (size_t i = 0; i < 4; i++)
		inventory[i] = NULL;
	// std::cout << "Name character constructor called" << std::endl;
} 

Character::Character(Character const &copy)
{
	*this = copy;
	// std::cout << "Character has been copied" << std::endl;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		if (inventory[i] != NULL)
			delete inventory[i];
	
	// std::cout << "Character has been killed" << std::endl;
}

Character& Character::operator=(Character const &copy)
{
	this->name = copy.name;
	
	for (size_t i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			this->inventory[i] = copy.inventory[i];
	// std::cout << "Assignation character completed" << std::endl;
	return (*this);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	size_t i = 0;
	while (i < 4)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m;
			break;
		}
		i++;
	}
}

void Character::unequip(int idx)
{
	if (idx < 0)
		return ;
	for (size_t i = idx; i < 3; i++)
	{
		this->inventory[i] = this->inventory[i + 1];
		this->inventory[i + 1] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}
