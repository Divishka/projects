#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : amount(0)
{
	for (size_t i = 0; i < 4; i++)
		this->sources[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy) : amount(0)
{
	for (size_t i = 0; i < 4; i++)
		this->learnMateria(copy.sources[i]->clone());
	
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < this->amount; i++)
		delete this->sources[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	for (size_t i = 0; i < this->amount; i++)
		delete this->sources[i];
	this->amount = 0;
	for (size_t i = 0; i < copy.amount; i++)
		this->learnMateria(copy.sources[i]->clone());
	for (size_t i = 0; i < 4; i++)
		this->sources[i] = NULL;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* copy)
{
	if (this->amount  == 4 || copy == NULL)
		return ;
	for (size_t i = 0; i < this->amount; i++)
		if (this->sources[i] == copy)
			return ;
	this->sources[this->amount++] = copy;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < this->amount; i++)
		if (this->sources[i]->getType() == type)
			return (this->sources[i]->clone());

	return (NULL);
}
