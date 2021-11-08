#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class Phone_book
{

    Contact m_contacts[8];
    int     m_count;

public:

    Phone_book();
    ~Phone_book();
    void add_contact();
    void search_contact();

};

#endif