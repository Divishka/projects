#include "Cat.hpp"

Cat::Cat(/* args */) : Animal()
{
	this->type = "Cat";
	brain = new Brain();

	std::cout << "Cat has been created " << std::endl;
}

Cat::Cat(std::string idea) : Animal()
{
	this->type = "Cat";
	brain = new Brain(idea);

	std::cout << "Cat has been created " << std::endl;
}

Cat& Cat::operator= (Cat const &copy)
{
	if (!this->brain)
		this->brain = new Brain();
	this->type = copy.type;
	brain->setIdeas(copy.brain->getIdeas());

	std::cout << "Cat has been assigned" << std::endl;
	return (*this);
}

Cat::Cat(Cat const &copy)
{
	*this = copy;

	std::cout << "Cat has been copied" << std::endl;
}

Cat::~Cat()
{
	delete brain;

	std::cout << "Cat has been killed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Mew ~ ~ ~ " << std::endl;
}

void Cat::sayIdea(unsigned int number)
{
	std::cout << brain->getIdea(number) << std::endl;
}

