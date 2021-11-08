#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal{

protected:


private:

	/* data */

public:

	WrongCat();
	WrongCat(WrongCat const &copy);
	WrongCat& operator= (WrongCat const &copy);
	virtual ~WrongCat();

	void makeSound() const;

};




#endif

