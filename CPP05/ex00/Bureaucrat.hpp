#pragma once
#include <iostream>

class Bureaucrat
{
	protected:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too high";
				
				};
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return "Grade is too low";
				};
		};
};

//ostream overload
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
