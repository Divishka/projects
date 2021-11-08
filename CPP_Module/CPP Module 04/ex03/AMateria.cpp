#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	// std::cout << "Type constructor AMateria called" << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
}

AMateria& AMateria::operator=(AMateria const &copy)
{
	this->type = copy.type;
	return (*this);
}

AMateria::~AMateria()
{
	// std::cout << "Default destructor AMateria called " << std::endl;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const & AMateria::getType() const
{
	return (this->type);
}
