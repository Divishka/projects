#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someIntern;
	Bureaucrat supervisor("Supervisor", 1);
	std::cout << supervisor << std::endl;
	Bureaucrat francis("Francis", 25);
	std::cout << francis << std::endl;

	Form* shrub = someIntern.makeForm("shrubbery creation", "home");
	std::cout << *shrub << std::endl;
	shrub->beSigned(supervisor);
	std::cout << *shrub << std::endl;
	shrub->execute(francis);

	try
	{
		Form *srub = someIntern.makeForm("GFGG", "school");
		(void)srub;
	}
	catch(const std::exception& exception)
	{
		std::cerr << exception.what() << '\n';
	}

	Form *pres = someIntern.makeForm("presidential pardon", "Francis");
	std::cout << *pres << std::endl;
	supervisor.signForm(*pres);
	pres->execute(supervisor);

	Form *roboti = someIntern.makeForm("robotomy request", "Bender");
	std::cout << *roboti << std::endl;
	roboti->beSigned(supervisor);
	roboti->execute(francis);
	francis.executeForm(*roboti);
	francis.executeForm(*roboti);

	Form* robot = someIntern.makeForm("robotomy request", "you");
	std::cout << *robot << std::endl;

	Form* president = someIntern.makeForm("presidential pardon", "you");
	std::cout << *president << std::endl;

	delete shrub;
	delete president;
	delete robot;
	delete roboti;
	delete pres;

	return (0);
}
