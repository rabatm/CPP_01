#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 1);
		Form form("form", 1, 1);
		std::cout << bureaucrat;
		std::cout << form;
		bureaucrat.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
	try {
		Bureaucrat bureaucrat("bureaucrat", 150);
		Form form("form", 150, 150);
		std::cout << bureaucrat;
		std::cout << form;
		bureaucrat.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

