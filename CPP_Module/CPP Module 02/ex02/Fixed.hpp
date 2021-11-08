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

	Fixed operator+	(Fixed const& operand) const;
	Fixed operator-	(Fixed const& operand) const;
	Fixed operator*	(Fixed const& operand) const;
	Fixed operator/	(Fixed const& operand) const;

	Fixed &operator++	(void);//pre-increment
	Fixed &operator--	(void);//pre-decrement
	Fixed operator++	(int);//post-increment
	Fixed operator--	(int);//post-decrement
	
	

	bool operator>	(Fixed const& operand) const;
	bool operator<	(Fixed const& operand) const;
	bool operator>=	(Fixed const& operand) const;
	bool operator<=	(Fixed const& operand) const;
	bool operator==	(Fixed const& operand) const;
	bool operator!=	(Fixed const& operand) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
	static			Fixed &min(Fixed &o1, Fixed &o2);
	const static	Fixed &min(const Fixed &o1, const Fixed &o2);
	static			Fixed &max(Fixed &o1, Fixed &o2);
	const static	Fixed &max(const Fixed &o1, const Fixed &o2);
	
};

Fixed &min(Fixed &o1, Fixed &o2);
Fixed &max(Fixed &o1, Fixed &o2);
std::ostream& operator<< (std::ostream &out, const Fixed &fixed);

#endif