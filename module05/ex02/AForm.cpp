#include "AForm.hpp"

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

AForm &AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm(){}

const std::string& AForm::getName() const {
	return const_cast<std::string&>(this->name);
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->signGrade;
}

int AForm::getGradeToExecute() const {
	return this->executeGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form: " << f.getName() << ", Sign Grade: " << f.getGradeToSign()
	   << ", Execute Grade: " << f.getGradeToExecute() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
	return os;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::executeCheck(const Bureaucrat& executor) const {
	if (!this->isSigned)
		throw std::runtime_error("Form is not signed");
	if (executor.getGrade() > this->executeGrade)
		throw GradeTooLowException();
}
