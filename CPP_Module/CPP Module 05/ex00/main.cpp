#include "Bureaucrat.hpp"

int main(void)
{
	//INcrement && DEcrement tests
	Bureaucrat carl("carl", 100);
	std::cout << carl << std::endl;
	carl.incrementGrade();
	std::cout << carl << std::endl;
	carl.decrementGrade();
	std::cout << carl << std::endl;

	//standart case
	try
	{
		Bureaucrat Carl("Carl", 5);
		std::cout << Carl << std::endl;
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	//tooHIGH case
	try
	{
		Bureaucrat Carl("Carl", 0);
		std::cout << Carl << std::endl;
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	//noraml >> tooLOW case
	try
	{
		Bureaucrat Carl("Carl", 150);
		std::cout << Carl << std::endl;
		Carl.decrementGrade();
		std::cout << Carl << std::endl;
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	//tooLOW case
	try
	{
		Bureaucrat Carl("Carl", 1000);
		std::cout << Carl << std::endl;
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	//normal >> tooHIGH case
	try
	{
		Bureaucrat Carl("Carl", 1);
		std::cout << Carl << std::endl;
		Carl.incrementGrade();
		std::cout << Carl << std::endl;
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	return (0);
}
