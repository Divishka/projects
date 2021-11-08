#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	
private:

	int					value;
	const static int	fractional_bits = 8;

public:

	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int integer);
	Fixed(const float floating);
	
	int toInt( void ) const;
	float toFloat( void ) const;

	Fixed& operator=(const Fixed &copy);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};

std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif