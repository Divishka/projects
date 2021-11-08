#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	this->type = "WrongAnimal";
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "???" << std::endl;
}

WrongAnimal& WrongAnimal::operator= (WrongAnimal const &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
}