#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;
	AForm* form;

	form = intern.makeForm("robotomy request", "Bender");
	if (form) {
		Bureaucrat boss("Boss", 1);
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "-----------------------------" << std::endl;

	form = intern.makeForm("invalid form", "Nobody");
	if (!form)
		std::cout << "No form created for invalid request.\n";

	return 0;
}

