#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), executeGrade(other.executeGrade) {}

Form &Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form(){}

const std::string& Form::getName() const {
	return const_cast<std::string&>(this->name);
}

bool Form::getIsSigned() const {
	return this->isSigned;
}

int Form::getGradeToSign() const {
	return this->signGrade;
}

int Form::getGradeToExecute() const {
	return this->executeGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form: " << f.getName() << ", Sign Grade: " << f.getGradeToSign()
	   << ", Execute Grade: " << f.getGradeToExecute() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
	return os;
}
