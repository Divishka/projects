#include "Bureaucrat.hpp"

int main(void)
{
	//Successful sign
	Bureaucrat Carl("Carl", 100);
	std::cout << Carl << std::endl;
	Form Test("Form 785", 140, 150);
	Carl.signForm(Test);


	//Grade is too low
	try
	{
		Bureaucrat Carl("Carl", 50);
		Form Test("Form 123", 10, 10);
		std::cout << Carl << std::endl << Test << std::endl;
		Carl.signForm(Test);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	//Grade is OK
	try
	{
		Bureaucrat Carl("Carl", 4);
		Form Test("Form 123", 10, 10);
		std::cout << Carl << std::endl << Test << std::endl;
		Carl.signForm(Test);
		std::cout << Test << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	//tooLow FORM EXCEPTION case
	try
	{
		Bureaucrat Carl("Carl", 4);
		Form Test("Form 123", -5, 155);
		std::cout << Carl << std::endl << Test << std::endl;
		Carl.signForm(Test);
		std::cout << Test << std::endl;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	return (0);
}
