#pragma once
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string const _target;
	public:
		PresidentialPardonForm(std::string const target);
		~PresidentialPardonForm();
		void execute(Bureaucrat const &executor) const;
};