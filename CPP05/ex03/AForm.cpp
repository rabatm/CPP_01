#include "AForm.hpp"


AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) : _name(other.getName()), _signed(other.getSigned()), _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute())
{
}

AForm::~AForm()
{
	std::cout << "AForm " << _name << " destroyed" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

AForm &AForm::operator=(AForm const &other)
{
	_signed = other.getSigned();
	return *this;
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	std::cout << AForm.getName() << ", AForm grade to sign " << AForm.getGradeToSign() << ", AForm grade to execute " << AForm.getGradeToExecute() << ", AForm signed " << AForm.getSigned() << std::endl;
	return out;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}