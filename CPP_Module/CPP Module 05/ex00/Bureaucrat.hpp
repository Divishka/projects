#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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
	
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat);


#endif
