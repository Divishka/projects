#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {

private:

	std::string formsNames[3];

public:

	class FormDoesNotExistException: public std::exception {
		virtual const char* what() const throw();
	};

	Intern();
	Intern(Intern const &other);
	virtual ~Intern();

	Intern& operator=(Intern const& other);

	Form* makeForm(std::string name, std::string target) const;
	
};

#endif
