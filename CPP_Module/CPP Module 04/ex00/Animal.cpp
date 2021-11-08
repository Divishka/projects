#include "Animal.hpp"

Animal::Animal(/* args */)
{
	this->type = "Animal";
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "???" << std::endl;
}

Animal& Animal::operator= (Animal const &copy)
{
	this->type = copy.type;
	return (*this);
}

Animal::Animal(Animal const &copy)
{
	*this = copy;
}

Animal::~Animal()
{
}