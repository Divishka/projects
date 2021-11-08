#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongDog : public WrongAnimal{

protected:


private:

	/* data */

public:

	WrongDog();
	WrongDog(WrongDog const &copy);
	WrongDog& operator= (WrongDog const &copy);
	virtual ~WrongDog();

	void makeSound() const;

};




#endif
