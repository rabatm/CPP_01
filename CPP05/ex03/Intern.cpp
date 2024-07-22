#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

static AForm *createShrubberyForm(const std::string target)
{
    return  (new ShrubberyCreationForm(target));
}

static AForm *createRobotomyRequestForm(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createPresidentialPardonForm(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const formName, std::string const target)
{
typedef AForm* (*FormCreator)(std::string const target);
        typedef struct {
            std::string formName;
            FormCreator creator;
        } FormPair;

        FormPair formPairs[] = {
            {"Shrubbery Creation Form", &createShrubberyForm},
            {"robotomy request", &createRobotomyRequestForm},
            {"Presidential Pardon Form", &createPresidentialPardonForm}
        };

        for (int i = 0; i < 3; i++) {
            if (formPairs[i].formName == formName) {
                std::cout << "Intern creates " << formName << std::endl;
                return formPairs[i].creator(target);
            }
        }

        std::cout << "Error: Form name doesn't exist" << std::endl;
        return nullptr;
}
