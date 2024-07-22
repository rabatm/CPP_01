#pragma once
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		Form();
		Form(std::string const name, int gradeToSign, int gradeToExecute);
		Form(Form const &other);
		Form &operator=(Form const &other);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
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

std::ostream &operator<<(std::ostream &out, Form const &form);