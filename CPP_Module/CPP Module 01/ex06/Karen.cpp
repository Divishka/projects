#include "Karen.hpp"

Karen::Karen() { }

Karen::~Karen() { }

void Karen::debug()
{ 
	std::cout << "[ DEBUG ]" << std:: endl 
	<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
	<< std::endl << std::endl;
}

void Karen::info()
{
	std::cout << "[ INFO ]" << std::endl 
	<< "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
	<< std::endl << std::endl;
}

void Karen::warning()
{
	std::cout << "[ WARNING ]" << std::endl 
	<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
	<< std:: endl << std::endl;
}

void Karen::error()
{
	std::cout << "[ ERROR ]" << std::endl 
	<< "This is unacceptable, I want to speak to the manager now."
	<< std:: endl << std::endl;
}

void Karen::complain( std::string level ) {

    std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = -1;

    while (i++ < 3) {
        if (str[i] == level) {
            switch (i) {
                case 0:
                    debug();
                case 1:
                    info();
                case 2:
                    warning();
                case 3:
                    error();
                    break;
                default:
                    break;
            }
            return;
        }
    }
    std::cout << "There is no instructions which Karen know" << std::endl;
}
