#include "Span.hpp"

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator i = begin;

    while (i != end)
    {
        if (array.size() == N)
            throw Span::FullSpanExtention();
        else
            array.push_back(*i);
        i++;
    }
}

void Span::addNumber(int number)
{
	if (this->array.size() == this->N)
		throw FullSpanExtention();
	this->array.push_back(number);
}

long Span::shortestSpan()
{
	if(this->array.size() <= 1)
		throw Span::CantSpan();

	long shortest = this->array[1] - this->array[0];
	if (shortest < 0)
		shortest *= -1;
	size_t array_size = this->array.size();
	size_t j;
	for (size_t i = 0; i < array_size; i++)
	{
		for (j = i + 1; j < array_size; j++)
		{
			long diff = this->array[j] - this->array[i];
			if (diff < 0)
				diff *= -1;
			if (diff < shortest)
				shortest = diff;
		}
	}
	return (shortest);
	
}

long Span::longestSpan()
{
	if(this->array.size() <= 1)
		throw Span::CantSpan();

	std::vector<int>::iterator min;
	std::vector<int>::iterator max;

	min = std::min_element(this->array.begin(), this->array.end());
	max = std::max_element(this->array.begin(), this->array.end());

	return (*max - *min);
}

Span::Span(unsigned int N)
{
	this->N = N;
}

Span::Span(Span const& copy)
{
	this->N = copy.N;
	this->array = copy.array;
}

Span& Span::operator= (Span const& copy)
{
	if (this == &copy)
		return (*this);
	this->N = copy.N;
	this->array = copy.array;
	return (*this);
}

Span::~Span()
{
	this->array.clear();
}
