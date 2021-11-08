#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T* arr, size_t length, void (*func)(T const& element));

template <typename T>
void display(T const& value);

#endif
