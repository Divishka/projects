#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {

private:

	const std::string Target;

public:

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm();

	virtual void execute(Bureaucrat const & executor) const;

	PresidentialPardonForm& operator=(PresidentialPardonForm const& other);
	Form* generate(std::string const &target);

};

#endif
