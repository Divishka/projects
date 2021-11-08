#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

template <typename T>
Array<T>::Array() : length(0), arr(NULL)
{
	
}

template <typename T>
Array<T>::Array(size_t n) : length(n), arr(NULL)
{
	this->arr = new T[n];
}

template <typename T>
Array<T>::Array(Array<T> const& copy) : length(0), arr(NULL)
{
	if (copy.length > 0)
	{
		this->arr = new T[copy.length];
		for (size_t i = 0; i < copy.length; i++)
		{
			this->arr[i] = copy.arr[i];
		}
	}
	this->length = copy.length;
}

template <typename T>
Array<T>::~Array()
{
	if (this->length > 0)
		delete this->arr;
}

template<typename T>
const char* Array<T>::OutOfLimitsException::what() const throw()
{
	return "ArrayException: indexs out of limits";
}

template <typename T>
Array<T>& Array<T>::operator= (Array<T> const& copy)
{
	if (this->length > 0)
		delete this->arr;
	*this = copy;
}

template <typename T>
T& Array<T>::operator[](const size_t index)
{
	if (index >= this->length || index < 0)
		throw Array::OutOfLimitsException();
	return (this->arr[index]);
}

template <typename T>
const T& Array<T>::operator[] (size_t index) const
{
	if (index >= this->length || index < 0)
		throw Array::OutOfLimitsException();
	return (this->arr[index]);
}

template <typename T>
size_t Array<T>::size() const
{
	return length;
}

int main(int, char**)
{
    Array<int> numbers(10);
    int* mirror = new int[10];

    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i;
        mirror[i] = i;
		std::cout << "mine array " << numbers[i] << "     true array " << mirror[i] << std::endl;
    }
	std::cout << "THEY'r EQUAL !" << std::endl << std::endl;

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (size_t i = 0; i < tmp.size(); i++)
		{
			std::cout << "assigned array number " << tmp[i] << "     copied array number " << test[i] << std::endl;
		}
    }
	std::cout << std::endl;
    for (int i = 0; i < 10; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[5] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << std::endl << "numbers[5] = " << numbers[5] << std::endl;
    delete [] mirror;//
    return 0;
}
