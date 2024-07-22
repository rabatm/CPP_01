#pragma once
#include <iostream>
#include "AForm.hpp"


class AForm;

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
		void signForm(AForm &form);
		void executeForm(AForm const &form);
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
