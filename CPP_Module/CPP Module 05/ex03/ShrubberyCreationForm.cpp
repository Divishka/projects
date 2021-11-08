#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	const std::string fileName = this->Target + "_shrubbery";
	std::ofstream outf(fileName);
	if (outf.bad() || !outf.is_open())
		throw OpenFileException();
	outf << "     	  /\\\n \
	     /\\*\\\n \
	    /\\O\\*\\\n \
	   /*/\\/\\/\\\n \
	  /\\O\\/\\*\\/\\\n \
	 /\\*\\/\\*\\/\\/\\\n \
	/\\O\\/\\/*/\\/O/\\\n \
	      ||\n \
	      ||\n \
	      ||\n  \
------------------------------- \n\
      \\/ \n\
      /\\ \n\
     /~~\\o \n\
    /o   \\ \n\
   /~~*~~~\\\n\
 o/      o \\\n\
 /~~~~~~~~~~\\\n\
/__*_________\\\n\
     || \n\
   \\====/\n\
    \\__/\n";
	if (outf.bad())
	{
		outf << std::endl;
		outf.close();
		throw (WriteFileException());
	}
	outf << std::endl;
	outf.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	Form("ShrubberyCreationForm", 145, 137), Target(target)
{
	if (this->getReqToSign() < 1 || this->getReqToExec() < 1)
		throw (GradeTooHighException());
	else if (this->getReqToSign() > 150 || this->getReqToExec() > 150)
		throw (GradeTooLowException());
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : 
	Form(other), Target(other.Target)
{
	if (this->getReqToSign() < 1 || this->getReqToExec() < 1)
		throw (GradeTooHighException());
	else if (this->getReqToSign() > 150 || this->getReqToExec() > 150)
		throw (GradeTooLowException());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (ShrubberyCreationForm const& other)
{
	(void)other;
	return (*this);
}

const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return ("ShrubberException: Can't open file");
}

const char* ShrubberyCreationForm::WriteFileException::what() const throw()
{
	return ("ShrubberException: Can't write to file");
}

Form *ShrubberyCreationForm::generate(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
