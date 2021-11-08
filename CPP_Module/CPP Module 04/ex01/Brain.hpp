#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {

private:

	std::string ideas[100];

public:

	Brain(/* args */);
	Brain(std::string idea);
	Brain(Brain const &copy);
	Brain& operator= (Brain const &copy);
	virtual ~Brain();
	
	std::string* getIdeas();
	std::string getIdea(unsigned int number);
	
	void setIdeas(std::string* ideas);
	
};








#endif
