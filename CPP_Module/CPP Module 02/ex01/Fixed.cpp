#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractional_bits;
}

Fixed::Fixed(const float floating)
{
	std::cout << "Float constructor called" << std::endl;
	//lost partiall part of float
	// this->value = (int)roundf(floating) << this->fractional_bits;
	this->value = (int)(roundf(floating * (1 << this->fractional_bits)));
}

int Fixed::toInt(void) const
{
	return ((int)(this->value >> this->fractional_bits));
}

float Fixed::toFloat(void) const
{
	//the same lost of the partiall part
	// return (float(this->value >> this->fractional_bits));
	return ((float)this->value / (float)(1 << this->fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
    this->value = copy.getRawBits();
}

std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
