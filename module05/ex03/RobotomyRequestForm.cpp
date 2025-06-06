#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string& RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	this->executeCheck(executor);
	std::cout << "Drrrrrr... Bzzzzzz... " << this->target << " has been robotomized successfully 50% of the time." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
	os << "Robotomy Request Form: " << form.getName() << ", Target: " << form.getTarget()
	   << ", Sign Grade: " << form.getGradeToSign() << ", Execute Grade: " << form.getGradeToExecute()
	   << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
	return os;
}
