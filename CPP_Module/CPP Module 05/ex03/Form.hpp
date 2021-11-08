#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

	const std::string	Name;
	bool 				Sign;
	const size_t		requieredGradeToSign;
	const size_t		requieredGradeToExec;

public:

	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
	class UnsignedFormException: public std::exception {
		virtual const char* what() const throw();
	};
	class FormAlreadySignedException: public std::exception {
		virtual const char* what() const throw();
	};

	Form();
	Form(std::string name, size_t reqSign, size_t reqExec);
	Form(Form const &other);
	virtual ~Form();

	Form& operator=(Form const& other);

	std::string getName() const;
	bool getSign() const;
	size_t getReqToSign() const;
	size_t getReqToExec() const;

	void beSigned(Bureaucrat const& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	
};

std::ostream& operator<<(std::ostream& out, Form const& Form);


#endif
