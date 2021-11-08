#include "Fixed.hpp"


/*-------------------C O N S T R U C T O R S--------------------*/

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int integer)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractional_bits;
}

Fixed::Fixed(const float floating)
{
	// std::cout << "Float constructor called" << std::endl;
	//lost partiall part of float
	// this->value = (int)roundf(floating) << this->fractional_bits;
	this->value = (int)(roundf(floating * (1 << this->fractional_bits)));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
    this->value = copy.getRawBits();
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}
/*-------------------------------------------------------------*/






/*--------------------------get & set--------------------------*/

int Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}
/*-------------------------------------------------------------*/





/*------------------T R A N S M I S S I O N--------------------*/

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

/*-------------------------------------------------------------*/



/*----------------------O V E R L O A D S----------------------*/

bool Fixed::operator> (Fixed const& operand) const
{
	return (this->value > operand.getRawBits());
}

bool Fixed::operator< (Fixed const& operand) const
{
	return (this->value < operand.getRawBits());
}

bool Fixed::operator>= (Fixed const& operand) const
{
	return (this->value >= operand.getRawBits());
}

bool Fixed::operator<= (Fixed const& operand) const
{
	return (this->value <= operand.getRawBits());
}

bool Fixed::operator== (Fixed const& operand) const
{
	return (this->value == operand.getRawBits());
}

bool Fixed::operator!= (Fixed const& operand) const
{
	return (this->value != operand.getRawBits());
}

Fixed Fixed::operator+ (Fixed const& operand) const
{
	Fixed out;
	out.setRawBits(operand.getRawBits() + this->value);
	return (out);
}

Fixed Fixed::operator- (Fixed const& operand) const
{
	Fixed out;
	out.setRawBits(this->value - operand.getRawBits());
	return (out);
}

Fixed Fixed::operator* (Fixed const& operand) const
{
	Fixed out;
	out.setRawBits(operand.getRawBits() * this->value >> this->fractional_bits);
	return (out);
}

Fixed Fixed::operator/ (Fixed const& operand) const
{
	Fixed out;
	out.setRawBits((this->value << this->fractional_bits) / operand.getRawBits());
	return (out);
}

Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed out(*this);
	operator++();
	return (out);
}

Fixed Fixed::operator--(int)
{
	Fixed out(*this);
	operator--();
	return (out);
}

Fixed &Fixed::min(Fixed &o1, Fixed &o2)
{
	return (o1 < o2 ? o1 : o2);
}

const Fixed &Fixed::min(const Fixed &o1, const Fixed &o2)
{
	return (o1 < o2 ? o1 : o2);
}

Fixed &Fixed::max(Fixed &o1, Fixed &o2)
{
	return (o1 > o2 ? o1 : o2);
}

const Fixed &Fixed::max(const Fixed &o1, const Fixed &o2)
{
	return (o1 > o2 ? o1 : o2);
}

Fixed& Fixed::operator= (const Fixed &copy)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}

Fixed &min(Fixed &o1, Fixed &o2)
{
	return (o1 < o2 ? o1 : o2);
}

Fixed &max(Fixed &o1, Fixed &o2)
{
	return (o1 > o2 ? o1 : o2);
}

std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
/*--------------------------------------------------------------*/
