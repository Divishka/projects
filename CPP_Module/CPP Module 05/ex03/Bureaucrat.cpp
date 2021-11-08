#include "Bureaucrat.hpp"

void Bureaucrat::executeForm(Form const& form)
{
	if (!form.getSign())
		std::cout << this->getName() << " can't execute " << form << " because it is unsigned" << std::endl;
	else if (this->getGrade() > form.getReqToExec())
		std::cout << this->getName() << " can't execute " << form << " because his grade is too low" << std::endl;
	else
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
}

void Bureaucrat::signForm(Form & form)
{
	if (form.getSign())
		std::cout << this->getName() << " can't sign " << form << " because it is already signed" << std::endl;
	else if (form.getReqToSign() < this->getGrade())
		std::cout << this->getName() << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : name(name), grade(grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other):
	name(other.name), grade(other.grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratException: Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratException: Grade too Low");
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}

std::string const& Bureaucrat::getName(void) const
{
	return (this->name);
}

size_t Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	this->grade--;
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	this->grade++;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}
