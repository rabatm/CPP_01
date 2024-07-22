#include "Form.hpp"


Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &other) : _name(other.getName()), _signed(other.getSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
}

Form::~Form()
{
	std::cout << "Form " << _name << " destroyed" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

Form &Form::operator=(Form const &other)
{
	_signed = other.getSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	std::cout << form.getName() << ", form grade to sign " << form.getGradeToSign() << ", form grade to execute " << form.getGradeToExecute() << ", form signed " << form.getSigned() << std::endl;
	return out;
}