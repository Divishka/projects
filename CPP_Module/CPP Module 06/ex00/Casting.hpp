#ifndef CASTING_HPP
#define CASTING_HPP

#include <string>
#include <iostream>
#include <typeinfo>
#include <cmath>
#include <limits>
#include <climits>
// #include <cstdint>

#define NON_DISPLAYABLE_CHARACTER -2

class Casting {

private:

	int flag_numberOfChars;
	int flag_numberOfNumbers;
	int flag_numberOfDots;
	int flag_numberOfF;
	int flag_numberOfMinuses;

	
	int flag_Pinf;
	int flag_Minf;
	int flag_nan;
	int flag_Pinff;
	int flag_Minff;
	int flag_nanf;
	int flag_char;
	int flag_int;
	int flag_float;
	int	flag_double;

	int amount;

	size_t	length;

	int		intCast;
	float	floatCast;
	double	doubleCast;
	char	charCast;
	

public:

	Casting(/* args */);
	Casting(std::string const& str);
	~Casting();

	void Parse(std::string const& stri);
	void show_cast_impossible();
	void show_char_from_int();
	void show_char_from_double();
	void show_char_from_float();
	

	// void from_char(char ch);
	// void from_double(double db);
	// void from_int(int i);
	// void from_float(float f);
	// void from_Pinf(double Pinf);
	// void from_Minf(double Minf);
	// void from_nan(double nan);
	// void from_Pinff(float Pinff);
	// void from_Minff(float Minff);
	// void from_nanf(float nanf);

	void from_char(std::string literal);
	void from_double(std::string literal);
	void from_int(std::string literal);
	void from_float(std::string literal);


	int getAmount() const;
	int getFlagInt() const;
	int getFlagChar() const;
	int getFlagFloat() const;
	int getFlagDouble() const;

};

std::ostream& operator<<(std::ostream& out, Casting const& literal);


#endif
