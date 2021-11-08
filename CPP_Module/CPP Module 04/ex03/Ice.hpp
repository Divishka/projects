#ifndef ICE_HPP
#define ICE_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class Ice : public AMateria{

public:

	Ice();
	Ice(Ice const &copy);
	Ice& operator=(Ice const &copy);
	virtual ~Ice();
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
