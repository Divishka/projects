#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal{

protected:


private:

	/* data */

public:

	Cat();
	Cat(Cat const &copy);
	Cat& operator= (Cat const &copy);
	virtual ~Cat();

	virtual void makeSound() const;

};




#endif

