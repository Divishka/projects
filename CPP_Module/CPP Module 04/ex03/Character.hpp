#ifndef CHARCTER_HPP
#define CHARCTER_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class Character : public ICharacter {

private:

	std::string name;
	AMateria *inventory[4];

public:

	Character();
	Character(std::string name);
	Character(Character const &copy);
	Character& operator= (Character const &copy);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

};

#endif
