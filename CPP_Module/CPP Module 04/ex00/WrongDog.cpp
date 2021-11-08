#include "WrongDog.hpp"

WrongDog::WrongDog(/* args */) : WrongAnimal()
{
	this->type = "WrongDog";
}

WrongDog& WrongDog::operator= (WrongDog const &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongDog::WrongDog(WrongDog const &copy)
{
	*this = copy;
}

WrongDog::~WrongDog()
{
}

void WrongDog::makeSound() const
{
	std::cout << "Woof!";
}

