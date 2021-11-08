#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class ICharacter;

class AMateria {

protected:

	//added
	std::string type;

public:

	AMateria(std::string const & type);

	//added
	AMateria();
	AMateria(AMateria const &copy);
	AMateria& operator=(AMateria const &copy);
	virtual ~AMateria();

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif
