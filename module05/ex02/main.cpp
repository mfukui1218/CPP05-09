#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 1);  // すべてのフォームに対応できる最高位

		// フォームを作成
		ShrubberyCreationForm shrub("garden");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Marvin");

		// Shrubbery
		bob.signForm(shrub);
		bob.executeForm(shrub);

		std::cout << "-----------------------------" << std::endl;

		// Robotomy
		bob.signForm(robot);
		bob.executeForm(robot);

		std::cout << "-----------------------------" << std::endl;

		// Pardon
		bob.signForm(pardon);
		bob.executeForm(pardon);

	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
