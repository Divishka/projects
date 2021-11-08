#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public Animal{

protected:


private:

	Brain* brain;

public:

	Cat();
	Cat(Cat const &copy);
	Cat(std::string idea);
	Cat& operator= (Cat const &copy);
	virtual ~Cat();

	void sayIdea(unsigned int number);
	virtual void makeSound() const;

};




#endif

