#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main()
{
	try
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat();
		Intern *z = new Intern();
		AForm *b = z->makeForm("Some Random Form", "Clown");
		b = z->makeForm("Presidential Pardon Form", "Clown");
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

