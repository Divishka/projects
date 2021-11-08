#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span {

private:

	unsigned int N;
	std::vector<int> array;

public:

	Span(unsigned int N);
	Span(Span const& copy);
    Span& operator=(Span const& copy);
	virtual ~Span();

	void	addNumber(int number);
	long	shortestSpan();
    long	longestSpan();
	void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	class CantSpan : public std::exception {
        virtual const char* what() const throw() { return ("Size of span is 1 or less"); }
    };

	class FullSpanExtention : public std::exception {
        virtual const char* what() const throw() { return ("Not enough space in the span to add the number"); }
    };
	int operator[] (size_t idx){return (array[idx]);}

};

#endif
