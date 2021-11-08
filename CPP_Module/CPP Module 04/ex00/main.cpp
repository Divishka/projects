#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "T R U E A N M I M A L S" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!

	std::cout << std::endl;

	j->makeSound();//will output the dog sound!

	std::cout << std::endl;

	meta->makeSound();//??? in the console

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* WAnim = new WrongAnimal();
	const WrongAnimal* WDog = new WrongDog();
	const WrongAnimal* WCat = new WrongCat();	

	std::cout << std::endl << "F A L S E A N M I M A L S" << std::endl;
	std::cout << WDog->getType() << " " << std::endl;
	std::cout << WCat->getType() << " " << std::endl;

	WCat->makeSound(); //will output the ???

	const WrongCat testCat;//will output Mew~~~
	testCat.makeSound();
	std::cout << std::endl;

	WDog->makeSound();//will output the ???	

	WAnim->makeSound();//??? in the console

	delete WAnim;
	delete WDog;
	delete WCat;

	return (0);
}