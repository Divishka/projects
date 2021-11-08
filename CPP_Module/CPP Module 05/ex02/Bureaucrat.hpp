#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Form.hpp"

class Form;

class Bureaucrat {
private:

	const std::string name;
	size_t grade;

public:

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(std::string name, size_t grade);
	Bureaucrat(Bureaucrat const &other);
	virtual ~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const& other);

	std::string const& getName(void) const;
	size_t getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);

	void signForm(Form & form);
	void executeForm(Form const& form);

};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat);


#endif
