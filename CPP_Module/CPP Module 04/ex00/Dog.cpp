#include "Dog.hpp"

Dog::Dog(/* args */) : Animal()
{
	this->type = "Dog";
}

Dog& Dog::operator= (Dog const &copy)
{
	this->type = copy.type;
	return (*this);
}

Dog::Dog(Dog const &copy)
{
	*this = copy;
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
	std::cout << "Woof!";
}
