#include "Intern.hpp"
#include "Intern.hpp"

Intern::Intern()
{
	formsNames[0] = "shrubbery creation";
	formsNames[1] = "robotomy request";
	formsNames[2] = "presidential pardon";
}

Form* Intern::makeForm(std::string name, std::string target) const
{
	Form* form[3] = {
		form[0] = new ShrubberyCreationForm(target),
		form[1] = new RobotomyRequestForm(target),
		form[2] = new PresidentialPardonForm(target)
	};
	size_t o = 0;
	for (size_t i = 0; i < 3; i++)
	{
		if (name.compare(formsNames[i]) == 0)
		{
			std::cout << "Intern creates " << *form[i] << std::endl;
			break;
		}
		o++;
	}
	if (o == 3)
	{
		for (size_t i = 0; i < 3; i++)
			delete form[i];
		throw (FormDoesNotExistException());
	}
	for (size_t i = 0; i < 3; i++)
	{
		if (i == o)
			continue;
		else
			delete form[i];
	}
	return (form[o]);
}

Intern::~Intern()
{
	
}

Intern::Intern(Intern const& other)
{
	(void)other;
}

Intern& Intern::operator= (Intern const& other)
{
	(void)other;
	return (*this);
}

const char* Intern::FormDoesNotExistException::what() const throw()
{
	return "InternException: Form does not exist";
}
