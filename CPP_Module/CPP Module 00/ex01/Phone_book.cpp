#include <iostream>
#include <string>
#include "Phone_book.hpp"

Phone_book::Phone_book()
{
	m_count = 0;
}

Phone_book::~Phone_book()
{
}

void Phone_book::search_contact()
{
    std::string str;
    std::cout.setf(std::ios::right);
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "firstname" << "|";
    std::cout << std::setw(10) << "secondname" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;

    for (int i = 0; i < m_count; i++)
    {
        std::cout << std::setw(10) << i << "|";
        str = m_contacts[i].get_first_name();
        if (str.length() > 10)
        {
            str.resize(10);
            str[9] = '.';
        }

        std::cout << std::setw(10) << str << "|";

        str = m_contacts[i].get_second_name();
        if (str.length() > 10)
        {
            str.resize(10);
            str[9] = '.';
        }
        std::cout << std::setw(10) << str << "|";

        str = m_contacts[i].get_nickname();
        if (str.length() > 10)
        {
            str.resize(10);
            str[9] = '.';
        }
        std::cout << std::setw(10) << str << std::endl;
    }

    while (1)
	{
        std::cout << "Which contact are you interested in? (index): ";
        std::getline(std::cin, str);
        int i = std::atoi(str.c_str());
        if (i >= m_count)
        {
            std::cout << "This book is so small :^( " << std::endl;
            break;
        }
        if (i < 0)
        {
            std::cout << "WRONG INDEX >:^(" << std::endl;
            break;
        }
        m_contacts[i].show_first_name();
        m_contacts[i].show_second_name();
        m_contacts[i].show_nickname();
        m_contacts[i].show_phone_number();
        m_contacts[i].show_darkest_secret();
        break;
    }

}

void Phone_book::add_contact()
{
    std::string str;

    if (m_count == 8)
        m_count = 7;

    std::cout << "First name: ";
    std::getline(std::cin, str);
    m_contacts[m_count].set_first_name(str);

    std::cout << "Second name: ";
    std::getline(std::cin, str);
    m_contacts[m_count].set_second_name(str);

    std::cout << "Nickname: ";
    std::getline(std::cin, str);
    m_contacts[m_count].set_nickname(str);

    std::cout << "Phone number: ";
    std::getline(std::cin, str);
    m_contacts[m_count].set_phone_number(str);

    std::cout << "Darkest secret: ";
    std::getline(std::cin, str);
    m_contacts[m_count].set_darkest_secret(str);

    if (m_count < 8)
        m_count++;
}
