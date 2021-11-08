#include "Brain.hpp"

Brain::Brain(/* args */)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = "omg";
	
	std::cout << "BRain  created" << std::endl;
}

Brain::Brain(std::string idea)
{
	for (size_t i = 0; i < 100; i++)
		ideas[i] = idea;
	
	std::cout << "BRain  created" << std::endl;
}

std::string* Brain::getIdeas()
{
	return (ideas);
}

std::string Brain::getIdea(unsigned int number)
{
	return (ideas[number]);
}

void Brain::setIdeas(std::string* ideas)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = ideas[i];
}

Brain::~Brain()
{
	std::cout << "Destruction of the brain" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	*this = copy;
	std::cout << "CopiED BrAinZ!" << std::endl;
}

Brain& Brain::operator=(Brain const &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "Assignation... of the brain..." << std::endl;
	return (*this);
}
