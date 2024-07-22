#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _target << " destroyed" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (rand() % 2)
		std::cout << _target << " 🦾 has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " 🤖 robotomization failed" << std::endl;
}