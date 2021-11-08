#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */) : WrongAnimal()
{
	this->type = "WrongCat";
}

WrongCat& WrongCat::operator= (WrongCat const &copy)
{
	this->type = copy.type;
	return (*this);
}

WrongCat::WrongCat(WrongCat const &copy)
{
	*this = copy;
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
	std::cout << "Mew ~ ~ ~ ";
}
