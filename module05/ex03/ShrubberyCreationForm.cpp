#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	this->executeCheck(executor);
	std::string filename = this->target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file) {
		throw std::ios_base::failure("Failed to open file");
	}
	file << "       _-_\n"
			"    /~~   ~~\\\n"
			"  /~~         ~~\\\n"
			" /~~             ~~\\\n"
			"/~~               ~~\\\n"
			"       |||\n";
	file.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
	os << "Shrubbery Creation Form: " << form.getName() << ", Target: " << form.getTarget()
	   << ", Sign Grade: " << form.getGradeToSign() << ", Execute Grade: " << form.getGradeToExecute()
	   << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
	return os;
}


