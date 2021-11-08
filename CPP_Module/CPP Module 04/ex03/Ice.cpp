#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// this->type = "ice";
}

Ice::Ice(Ice const &copy) : AMateria("ice")
{
	// *this = copy;
	(void)copy;
}

Ice& Ice::operator=(Ice const &copy)
{
	this->type = copy.type;
	return (*this);
}

Ice::~Ice()
{
	//under the question
	// delete this;
}

AMateria* Ice::clone() const
{
	return (new Ice(/*this*/));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots ice bolt at " << target.getName() << " *" << std::endl;
}

