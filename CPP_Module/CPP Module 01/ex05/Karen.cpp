#include "Karen.hpp"

Karen::Karen(/* args */) {
}

Karen::~Karen() {
}

void Karen::debug() 	{ std::cout << "debug" 		<< std:: endl; }
void Karen::info() 		{ std::cout << "info" 		<< std:: endl; }
void Karen::warning() 	{ std::cout << "warning" 	<< std:: endl; }
void Karen::error() 	{ std::cout << "error" 		<< std:: endl; }

// 2nd variant
// typedef void (Karen::*pointer_to_func)(void);

void Karen::complain( std::string level )
{
    std::string str[4] = { "debug", "info", "warning", "error" };

	//2nd variant
	//pointer_to_func func_array[4];

    void (Karen::*func_array[4])(void);
	func_array[0] = &Karen::debug;
	func_array[1] = &Karen::info;
	func_array[2] = &Karen::warning;
	func_array[3] = &Karen::error;

    for (int i = 0; i < 4; i++)
        if (str[i] == level)
            (this->*func_array[i])();
}
