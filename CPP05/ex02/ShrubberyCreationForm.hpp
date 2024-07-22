#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string const _target;
	public:
		ShrubberyCreationForm(std::string const target);
		~ShrubberyCreationForm();
		void execute(Bureaucrat const &executor) const;
};
