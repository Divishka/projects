#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
void easyfind(T& container, int element);

class NotFound : public std::exception {
    virtual const char* what() const throw() { return ("Not found."); }
};

#endif
