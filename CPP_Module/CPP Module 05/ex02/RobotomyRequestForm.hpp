#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {

private:

	const std::string Target;

public:

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm();

	virtual void execute(Bureaucrat const & executor) const;

	RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

};


#endif
