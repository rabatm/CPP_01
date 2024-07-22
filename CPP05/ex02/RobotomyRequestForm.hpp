#include "AForm.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string const _target;
	public:
		RobotomyRequestForm(std::string const target);
		~RobotomyRequestForm();
		void execute(Bureaucrat const &executor) const;
};