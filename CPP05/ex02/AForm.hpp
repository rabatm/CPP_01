#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		~AForm();
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
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

std::ostream &operator<<(std::ostream &out, AForm const &AForm);