#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"


int main()
{
	Animal *Animals[10];
	for (size_t i = 0; i < 10; i++)
	{
		switch (i % 2)
		{
			case (1):
	
				Animals[i] = new Cat();
				break;
	
			case (0):
				Animals[i] = new Dog();
				break;
		default:
			break;
		}
	}
	Animals[0]->makeSound();


	Animals[3]->makeSound();
	std::cout << std::endl;
	Animals[4]->makeSound();
	std::cout << std::endl;
	
	for (size_t i = 0; i < 10; i++)
		delete Animals[i];

	std::cout << "_____________________________" << std::endl;
	//creating new animal this ideas "omg"
	Cat omg;
	omg.sayIdea(7);
	//creating new animal this ideas "HELLO"
	Cat* hello = new Cat("Hello");

	//deep copy
	omg = *hello;

	//now both of them thinks about "HELLO"
	hello->sayIdea(7);
	omg.sayIdea(7);

	delete hello;

	std::cout << "_____________________________" << std::endl;
	
	//two brains has been created
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << "_____________________________" << std::endl;
	return (0);
}