#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _target << " destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
        std::ofstream file(this->_target + "_shrubbery");
        if (file.is_open()) {
            file << "ASCII tree";
            file.close();
        }
}
