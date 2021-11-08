#include <string>
#include <iostream>

int main()
{
    std::string STRING("HI THIS IS BRAIN");
    std::string *stringPTR = &STRING;
    std::string &stringREF = STRING;

    std::cout << &STRING << std::endl << stringPTR << std::endl << &stringREF << std::endl;
    std::cout << *stringPTR << std::endl << stringREF << std::endl;
    return (0);
}
