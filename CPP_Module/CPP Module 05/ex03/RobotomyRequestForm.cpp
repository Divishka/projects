#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	Form::execute(executor);
	std::cout << "* SOME DRRRRRRRRRRRRRRRRRRR`ILLING NOISES *" <<std::endl;
	if (std::rand() % 100 > 50)
		std::cout << this->Target << " had been robotomized successfully 50\% of the time" << std::endl;
	else
		std::cout << "robotomized failure" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	Form("RobotomyRequestForm", 72, 45), Target(target)
{
	if (this->getReqToSign() < 1 || this->getReqToExec() < 1)
		throw (GradeTooHighException());
	else if (this->getReqToSign() > 150 || this->getReqToExec() > 150)
		throw (GradeTooLowException());
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other):
	Form(other), Target(other.Target)
{
	if (this->getReqToSign() < 1 || this->getReqToExec() < 1)
		throw (GradeTooHighException());
	else if (this->getReqToSign() > 150 || this->getReqToExec() > 150)
		throw (GradeTooLowException());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator= (RobotomyRequestForm const& other)
{
	(void)other;
	return (*this);
}

Form *RobotomyRequestForm::generate(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}
