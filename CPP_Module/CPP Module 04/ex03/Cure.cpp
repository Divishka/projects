#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// this->type = "Cure";
}

Cure::Cure(Cure const &copy) : AMateria("cure")
{
	// *this = copy;
	(void)copy;
}

Cure& Cure::operator=(Cure const &copy)
{
	this->type = copy.type;
	return (*this);
}

Cure::~Cure()
{
	//under the question
	// delete this;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}




