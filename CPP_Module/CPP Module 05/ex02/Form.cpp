#include "Form.hpp"

void Form::execute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->requieredGradeToExec)
		throw Form::GradeTooLowException();
	if (!this->Sign)
		throw Form::UnsignedFormException();
}

void Form::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getReqToSign())
		throw (GradeTooLowException());
	else if (this->Sign)
		throw Form::FormAlreadySignedException();
	this->Sign = true;
}

Form::Form(std::string name, size_t reqSign, size_t reqExec) : 
	Name(name), Sign(false), requieredGradeToSign(reqSign), requieredGradeToExec(reqExec)
{
	if (this->requieredGradeToExec < 1 || this->requieredGradeToSign < 1)
		throw (GradeTooHighException());
	else if (this->requieredGradeToSign > 150 || this->requieredGradeToExec > 150)
		throw (GradeTooLowException());
}

Form::Form(Form const& other):
	Name(other.Name), Sign(other.Sign), 
	requieredGradeToSign(other.requieredGradeToSign), requieredGradeToExec(other.requieredGradeToExec)
{
	if (this->requieredGradeToExec < 1 || this->requieredGradeToSign < 1)
		throw (GradeTooHighException());
	else if (this->requieredGradeToSign > 150 || this->requieredGradeToExec > 150)
		throw (GradeTooLowException());
}

Form::~Form()
{
	
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

const char* Form::UnsignedFormException::what() const throw()
{
	return ("FormException: Unsigned form can't be executed");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "FormException: The Form is already signed";
}

Form& Form::operator=(Form const &other)
{
	this->Sign = other.Sign;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->Name);
}

bool Form::getSign() const
{
	return (this->Sign);
}

size_t Form::getReqToSign() const
{
	return (requieredGradeToSign);
}

size_t Form::getReqToExec() const
{
	return (requieredGradeToExec);
}

std::ostream& operator<<(std::ostream& out, Form const& Form)
{
	if (Form.getSign() == true)
		out << "Form " << Form.getName() << " is signed;    REQUIREMENTS: to SIGN - "
		<< Form.getReqToSign() << ", to EXECUTE - " << Form.getReqToExec();
	else
		out << "Form " << Form.getName() << " isn't signed;    REQUIREMENTS: to SIGN - "
		<< Form.getReqToSign() << ", to EXECUTE - " << Form.getReqToExec();
	return (out);
}
