#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	//Grade is too low
	try
	{
		Bureaucrat Carl("Carl", 1);
		std::cout << Carl << std::endl;
		Form *Test = new ShrubberyCreationForm("home");
		Carl.signForm(*Test);
		Test->execute(Carl);
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	// //Grade is OK


	// srand(time(NULL));

	Bureaucrat supervisor("Supervisor", 1);
	std::cout << supervisor << std::endl;
	Bureaucrat francis("Francis", 25);
	std::cout << francis << std::endl;

	std::cout << "1---1" << std::endl;

	Form *shrub = new ShrubberyCreationForm("home");
	std::cout << *shrub << std::endl;	//isnt signed
	shrub->beSigned(supervisor);		//signing
	std::cout << *shrub << std::endl;	//signed
	shrub->execute(francis);			//executing

	std::cout << "2---2" << std::endl;

	Form *pres = new PresidentialPardonForm("Francis");
	std::cout << *pres << std::endl;	//isn't signed
	supervisor.signForm(*pres);			//signing
	std::cout << *pres << std::endl;	//signed
	pres->execute(supervisor);			//executing

	std::cout << "3---3" << std::endl;

	Form *robot = new RobotomyRequestForm("Bender");
	std::cout << *robot << std::endl;	//isn't signed
	robot->beSigned(supervisor);		//signing
	std::cout << *robot << std::endl;	//signed
	robot->execute(francis);			//executing
	francis.executeForm(*robot);		//executing
	francis.executeForm(*robot);		//executing

	std::cout << "4---4" << std::endl;

	try
	{
		francis.executeForm(*pres);
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "5---5" << std::endl;

	try
	{
		RobotomyRequestForm robot = RobotomyRequestForm("Bender");
		std::cout << robot << std::endl;
		robot.execute(supervisor);
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "6---6" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Francis");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		std::cout << pres << std::endl;
		pres.execute(francis);
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	std::cout << "7---7" << std::endl;

	try
	{
		PresidentialPardonForm pres = PresidentialPardonForm("Francis");
		std::cout << pres << std::endl;
		supervisor.signForm(pres);
		std::cout << pres << std::endl;
		francis.executeForm(pres);
	}
	catch(std::exception const &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	delete shrub;
	delete pres;
	delete robot;

	return (0);
}
