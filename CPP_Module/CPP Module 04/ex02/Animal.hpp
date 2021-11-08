#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

protected:

	std::string type;

private:

	/* data */

public:

	Animal();
	Animal(Animal const &copy);
	Animal& operator= (Animal const &copy);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const = 0;

};




#endif
