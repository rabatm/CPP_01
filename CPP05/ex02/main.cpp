#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		Bureaucrat b2("Bureaucrat2", 150);
		ShrubberyCreationForm s1("ShrubberyCreationForm1");
		RobotomyRequestForm r1("RobotomyRequestForm1");
		PresidentialPardonForm p1("PresidentialPardonForm1");

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << s1 << std::endl;
		std::cout << r1 << std::endl;
		std::cout << p1 << std::endl;

		b1.signForm(s1);
		b1.signForm(r1);
		b1.signForm(p1);

		b1.executeForm(s1);
		b1.executeForm(r1);
		b1.executeForm(p1);

		b2.signForm(s1);
		b2.signForm(r1);
		b2.signForm(p1);

		b2.executeForm(s1);
		b2.executeForm(r1);
		b2.executeForm(p1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

