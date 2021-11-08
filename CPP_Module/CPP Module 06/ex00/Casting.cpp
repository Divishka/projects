#include "Casting.hpp"

Casting::Casting(/* args */)
{
}

void Casting::show_char_from_int()
{
	if (intCast < CHAR_MIN || intCast > CHAR_MAX || intCast < 0)
		std::cout << "char: impossible" << std::endl;
	else if (charCast >= 0 && charCast <= 31)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: '" << charCast << "'" << std::endl;
}

void Casting::show_char_from_double()
{
	if (doubleCast < CHAR_MIN || doubleCast > CHAR_MAX || doubleCast < 0)
		std::cout << "char: impossible" << std::endl;
	else if (charCast >= 0 && charCast <= 31)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: '" << charCast << "'" << std::endl;
}

void Casting::show_char_from_float()
{
	if (floatCast < CHAR_MIN || floatCast > CHAR_MAX || floatCast < 0)
		std::cout << "char: impossible" << std::endl;
	else if (charCast >= 0 && charCast <= 31)
		std::cout << "char: not displayable" << std::endl;
	else
		std::cout << "char: '" << charCast << "'" << std::endl;
}

void Casting::show_cast_impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatCast << "f" << std::endl;
	std::cout << "double: " << doubleCast << std::endl;
}

void Casting::Parse(std::string const& stri)
{
	flag_char = 0;
	flag_double = 0;
	flag_numberOfNumbers = 0;
	flag_numberOfChars = 0;
	flag_numberOfF = 0;
	flag_int = 0;
	flag_float = 0;
	flag_numberOfDots = 0;
	amount = 0;
	flag_numberOfMinuses = 0;
	flag_Pinf = 0;
	flag_Minf = 0;
	flag_nan = 0;
	flag_Pinff = 0;
	flag_Minff = 0;
	flag_nanf = 0;

	std::string str;
	if (stri.length() == 3 && stri[0] == '\'' && stri[2] == '\'')
	{
		str = stri[1];//probably add '\0' to the end
		flag_char = 1;
		flag_numberOfChars = 1;
	}
	else if (stri.length() == 1 && stri[0] == '-')
	{
		std::cout << "incorrect literal" << std::endl;
		exit(1);
	}
	else if (stri.compare("-inf") == 0 || stri.compare("+inf") == 0 || stri.compare("nan") == 0)
	{
		if (stri.compare("-inf") == 0)
			flag_Minf = 1;
		if (stri.compare("+inf") == 0)
			flag_double = 1;
		if (stri.compare("nan") == 0)
			flag_nan = 1;
	}
	else if (stri.compare("-inff") == 0 || stri.compare("+inff") == 0 || stri.compare("nanf") == 0)
	{
		if (stri.compare("-inff") == 0)
			flag_Minff = 1;
		if (stri.compare("+inff") == 0)
			flag_Pinff = 1;
		if (stri.compare("nanf") == 0)
			flag_nanf = 1;
	}
	else if ((stri[0] >= '0' && stri[0] <= '9') || stri[0] == '-')
		str = stri;
	else
	{
		std::cout << "incorrect literal" << std::endl;
		exit(1);
	}
	this->length = str.length();
	
	for (size_t i = 0; i < this->length; i++)
	{
		if (str[i] >= 0 && str[i] <= 31)
			exit(NON_DISPLAYABLE_CHARACTER);
		if (isdigit(str[i]))
			flag_numberOfNumbers++;
		if (!isdigit(str[i]) && flag_char != 1)
			flag_numberOfChars++;
		if (str[i] == '.')
			flag_numberOfDots++;
		if (str[i] == 'f')
			flag_numberOfF++;
		if (str[i] == '-')
			flag_numberOfMinuses++;
	}

	if (flag_Pinf == 0 && flag_Minf == 0 && flag_nan == 0 && flag_Pinff == 0 && flag_Minff == 0 && flag_nanf == 0)
	{
		if ((flag_numberOfDots == 1 && flag_numberOfF == 0 && flag_numberOfNumbers > 1 && (flag_numberOfMinuses <= 1 && str.find_first_of('-') == 0)) || (flag_numberOfDots == 1 && flag_numberOfF == 0  && flag_numberOfNumbers > 1)) 
		{
			if (flag_numberOfMinuses <= 1 && str.find_first_of('-') == 0)
				flag_numberOfChars--;
			flag_double = 1;
		}

		if ((flag_char != 1 && flag_numberOfDots == 1 && flag_numberOfF == 1  && flag_numberOfNumbers > 1 && flag_numberOfMinuses <= 1 && str.find_first_of('-') == 0 && str.find_last_of('f') == 0) || (flag_char != 1 && flag_numberOfDots == 1 && flag_numberOfF == 1  && flag_numberOfNumbers > 1 && str.find_last_of('f') == str.length() - 1))
			{
				if (flag_numberOfMinuses <= 1 && str.find_first_of('-') == 0)
					flag_numberOfChars--;
				flag_float = 1;
			}

		if (flag_char != 1 && flag_numberOfNumbers > 0 && flag_double != 1 && flag_float != 1 && (flag_numberOfMinuses == 1 || str.find_first_of('-')))
			{
				if (flag_numberOfMinuses <= 1 && str.find_first_of('-') == 0)
					flag_numberOfChars--;
				flag_int = 1;
			}

		if (flag_numberOfChars > 0 && flag_float != 1 && flag_double != 1)
		{
			flag_char = flag_numberOfChars;
		}
	 // if ((flag_numberOfChars > 1 && flag_float != 1 && flag_double != 1) || flag_numberOfMinuses > 1) was
		if ((flag_numberOfChars > 1 && flag_numberOfDots == 1 && flag_numberOfMinuses == 1) || flag_numberOfMinuses > 1)
		{
			std::cout << "2+ chars" << std::endl;
			exit(1);
		}
		if (flag_numberOfDots > 1)
		{
			std::cout << "2+ dots" << std::endl;
			exit(1);
		}
		if (flag_numberOfF > 1)
		{
			std::cout << "2+ 'f' symbol" << std::endl;
			exit(1);
		}

		// std::cout << *this << std::endl;
		amount = flag_char + flag_int + flag_double + flag_float;

		if (amount > 1)
		{
			std::cout << "incorrect literal" << std::endl;
			exit(1);
		}
	}
	if (flag_Pinf == 1 || flag_nan == 1 || flag_Minf == 1)
		flag_double = 1;
	if (flag_Pinff == 1 || flag_nanf == 1 || flag_Minff == 1)
		flag_float = 1;
}

void Casting::from_char(std::string literal)
{
	/* * * * * * * * * * * * * * * * * * * C A S T S * * * * * * * * * * * * * * * * * * * */
	charCast = static_cast<char>(literal[1]);
	intCast = static_cast<int>(charCast);
	doubleCast = static_cast<double>(charCast);
	floatCast = static_cast<float>(charCast);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	std::cout << "char: '" << charCast << "'" << std::endl;
	std::cout << "int: " << intCast << std::endl;
	std::cout << "float: " << floatCast <<   ".0f" << std::endl;
	std::cout << "double: " << doubleCast <<  ".0" << std::endl;
}

void Casting::from_int(std::string literal)
{
	intCast = std::stoi(literal);

	/* * * * * * * * * * * * * * * * * * * C A S T S * * * * * * * * * * * * * * * * * * * */
	charCast = static_cast<char>(intCast);
	doubleCast = static_cast<double>(intCast);
	floatCast = static_cast<float>(intCast);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	this->show_char_from_int();	
	std::cout << "int: " << intCast << std::endl;
	std::cout << "float: " << floatCast <<   ".0f" << std::endl;
	std::cout << "double: " << doubleCast <<  ".0" << std::endl;
}

void Casting::from_double(std::string literal)
{
	if (literal == "nan")
		doubleCast = NAN;
	else if (literal == "+inf")
		doubleCast = +INFINITY;
	else if (literal == "-inf")
		doubleCast = -INFINITY;
	else
		doubleCast = std::stof(literal);
	
	/* * * * * * * * * * * * * * * * * * * C A S T S * * * * * * * * * * * * * * * * * * * */
	intCast = static_cast<int>(doubleCast);
	floatCast = static_cast<float>(doubleCast);
	charCast = static_cast<char>(doubleCast);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	if (literal == "nan")
		this->show_cast_impossible();
	else if (doubleCast == +INFINITY)
		this->show_cast_impossible();
	else if (doubleCast == -INFINITY)
		this->show_cast_impossible();
	else
	{
		this->show_char_from_double();
		if (doubleCast > INT_MAX || doubleCast < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << intCast << std::endl;

		if (floor(doubleCast) == doubleCast)
		{
			if (doubleCast != floatCast)
				std::cout << "float: impossible" << std::endl;
			else
				std::cout << "float: " << floatCast << ".0f" << std::endl;
			std::cout << "double: " << doubleCast << ".0" << std::endl;
		}
		else
		{
			if (doubleCast > __FLT_MAX__ && doubleCast < __FLT_MAX__ + 1)
				std::cout << "float: impossible" << std::endl;
			else
				std::cout << "float: " << floatCast << "f" << std::endl;
			std::cout << "double: " << doubleCast << std::endl;
		}
	}
}

void Casting::from_float(std::string literal)
{
	if (literal == "nanf")
		floatCast = NAN;
	else if (literal == "+inff")
		floatCast = +INFINITY;
	else if (literal == "-inff")
		floatCast = -INFINITY;
	else
		floatCast = std::stof(literal);

	/* * * * * * * * * * * * * * * * * * * C A S T S * * * * * * * * * * * * * * * * * * * */
	floatCast = std::stof(literal);
	intCast = static_cast<int>(floatCast);
	doubleCast = static_cast<double>(floatCast);
	charCast = static_cast<char>(floatCast);
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

	if (literal == "nanf")
		this->show_cast_impossible();
	else if (floatCast == +INFINITY)
		this->show_cast_impossible();
	else if (floatCast == -INFINITY)
		this->show_cast_impossible();
	else
	{
		this->show_char_from_float();

		if (floatCast > INT_MAX || floatCast < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << intCast << std::endl;
		if (floor(floatCast) == floatCast)
		{
			std::cout << "float: " << floatCast << ".0f" << std::endl;
			std::cout << "double: " << doubleCast << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << floatCast << "f" << std::endl;
			std::cout << "double: " << doubleCast << std::endl;
		}
	}
}

Casting::Casting(std::string const& str)
{
	Parse(str);
	if (flag_char == 1)
		from_char(str);
	if (flag_double == 1)
		from_double(str);
	if (flag_int == 1)
		from_int(str);
	if (flag_float == 1)
		from_float(str);

}

std::ostream& operator<< (std::ostream& out, Casting const& literal)
{
	out << "Amount " << literal.getAmount() << std::endl << " is Int " << literal.getFlagInt() << std::endl 
	<< " is Char " << literal.getFlagChar() << std::endl << " is Float " << literal.getFlagFloat() << std::endl
	<< " is Double " << literal.getFlagDouble();
	return (out);
}

Casting::~Casting()
{
}

int Casting::getAmount() const
{
	return (amount);
}

int Casting::getFlagInt() const
{
	return (flag_int);
}

int Casting::getFlagChar() const
{
	return (flag_char);
}

int Casting::getFlagFloat() const
{
	return (flag_float);
}

int Casting::getFlagDouble() const
{
	return (flag_double);
}
