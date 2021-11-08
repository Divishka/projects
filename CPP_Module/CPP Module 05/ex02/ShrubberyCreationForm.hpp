#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form;

class ShrubberyCreationForm : public Form {

private:

	const std::string Target;

public:

	class OpenFileException: public std::exception {
		virtual const char* what() const throw();
	};
	class WriteFileException: public std::exception {
		virtual const char* what() const throw();
	};

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	virtual ~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const & executor) const;

	ShrubberyCreationForm& operator=(ShrubberyCreationForm const& other);
	
};

std::ostream& operator<<(std::ostream& out, ShrubberyCreationForm const& ShrubberyCreationForm);


#endif
