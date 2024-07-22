#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other.getName()), _grade(other.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	_grade = other.getGrade();
	return *this;
}
 std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	std::cout << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return out;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
	}
}