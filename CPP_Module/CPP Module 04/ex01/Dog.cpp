#include "Dog.hpp"

Dog::Dog(/* args */) : Animal()
{
	this->type = "Dog";
	brain = new Brain();

	std::cout << "Dog has been created " << std::endl;
}

Dog& Dog::operator= (Dog const &copy)
{
	if (!this->brain)
		this->brain = new Brain();
	this->type = copy.type;
	brain->setIdeas(copy.brain->getIdeas());

	std::cout << "Dog has been assigned" << std::endl;
	return (*this);
}

Dog::Dog(Dog const &copy)
{
	*this = copy;

	std::cout << "Dog has been copied" << std::endl;
}

Dog::~Dog()
{
	delete brain;

	std::cout << "Dog has been killed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

