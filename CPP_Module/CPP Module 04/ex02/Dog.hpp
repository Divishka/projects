#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>


class Dog : public Animal{

protected:


private:

	Brain* brain;

public:

	Dog();
	Dog(Dog const &copy);
	Dog& operator= (Dog const &copy);
	virtual ~Dog();

	virtual void makeSound() const;

};




#endif
