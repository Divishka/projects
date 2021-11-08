#include <iostream>
#include "Contact.hpp"
#include "Phone_book.hpp"

int main()
{
    Phone_book book;
    std::string cmd;

    while (1)
    {
        std::cout << "\n>What do you want? (ADD, SEARCH and EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd != "EXIT" && cmd != "SEARCH" && cmd != "ADD")
            std::cout << "Worng command";
        if (cmd == "EXIT")
            break;
        if (cmd == "ADD")
            book.add_contact();
        if (cmd == "SEARCH")
            book.search_contact();
    }
    return (0);
}