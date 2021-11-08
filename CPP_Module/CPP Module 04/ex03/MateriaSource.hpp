#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

private:

	size_t amount;
	AMateria* sources[4];	

public:

	MateriaSource();
	MateriaSource(MateriaSource const &copy);
	MateriaSource& operator=(MateriaSource const &copy);
	virtual ~MateriaSource();
	
	virtual void learnMateria(AMateria* copy);
	virtual AMateria* createMateria(std::string const & type);
	
};

#endif
