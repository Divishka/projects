#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	Form::execute(executor);
	std::cout << this->Target << " has been pardoned by Zafod Beeblevrox" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	Form("PresidentialPardonForm", 25, 5), Target(target)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other):
	Form(other), Target(other.Target)
{
	
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator= (PresidentialPardonForm const& other)
{
	(void)other;
	return (*this);
}

Form *PresidentialPardonForm::generate(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}
