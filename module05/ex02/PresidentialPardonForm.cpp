#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target(other.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string& PresidentialPardonForm::getTarget() const {
	return this->target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->executeCheck(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form) {
	os << "Presidential Pardon Form: " << form.getName() << ", Target: " << form.getTarget()
	   << ", Sign Grade: " << form.getGradeToSign() << ", Execute Grade: " << form.getGradeToExecute()
	   << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
	return os;
}


