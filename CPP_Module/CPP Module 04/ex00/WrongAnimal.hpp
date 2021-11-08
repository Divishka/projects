#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

protected:

	std::string type;

private:

	/* data */

public:

	WrongAnimal();
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal& operator= (WrongAnimal const &copy);
	virtual ~WrongAnimal();

	std::string getType() const;
	void makeSound() const;

};




#endif
