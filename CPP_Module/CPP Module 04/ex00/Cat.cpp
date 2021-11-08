#include "Cat.hpp"

Cat::Cat(/* args */) : Animal()
{
	this->type = "Cat";
}

Cat& Cat::operator= (Cat const &copy)
{
	this->type = copy.type;
	return (*this);
}

Cat::Cat(Cat const &copy)
{
	*this = copy;
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
	std::cout << "Mew ~ ~ ~ ";
}
