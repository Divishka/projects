#include <iostream>
#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void            Contact::show_first_name() { std::cout << m_first_name << std::endl; }
void            Contact::show_second_name() { std::cout << m_second_name << std::endl; }
void            Contact::show_nickname() { std::cout << m_nickname << std::endl; }
void            Contact::show_phone_number() { std::cout << m_phone_number << std::endl; }
void            Contact::show_darkest_secret() { std::cout << m_darkest_secret << std::endl; }

std::string     Contact::get_first_name() { return (m_first_name); }
std::string     Contact::get_second_name() { return (m_second_name); }
std::string     Contact::get_nickname() { return (m_nickname); }
std::string     Contact::get_phone_number() { return (m_phone_number); }
std::string     Contact::get_darkest_secret() { return (m_darkest_secret); }

void Contact::set_first_name(std::string str)
{
    m_first_name = str;
}

void Contact::set_second_name(std::string str)
{
    m_second_name = str;
}

void Contact::set_nickname(std::string str)
{
    m_nickname = str;
}

void Contact::set_phone_number(std::string str)
{
    m_phone_number = str;
}

void Contact::set_darkest_secret(std::string str)
{
    m_darkest_secret = str;
}
