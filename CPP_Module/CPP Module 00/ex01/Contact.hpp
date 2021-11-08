#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{

private:
    // int         index;
    std::string		m_first_name;
    std::string		m_second_name;
    std::string		m_nickname;
    std::string		m_phone_number;
    std::string		m_darkest_secret;

public:

    Contact();
    ~Contact();
    void            show_first_name();
    void            show_second_name();
    void            show_nickname();
    void            show_phone_number();
    void            show_darkest_secret();

    std::string     get_first_name();
    std::string     get_second_name();
    std::string     get_nickname();
    std::string     get_phone_number();
    std::string     get_darkest_secret();

    void            set_first_name(std::string str);
    void            set_second_name(std::string str);
    void            set_nickname(std::string str);
    void            set_phone_number(std::string str);
    void            set_darkest_secret(std::string str);

};

#endif
