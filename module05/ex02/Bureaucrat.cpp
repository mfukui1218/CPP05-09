#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

const std::string& Bureaucrat::getName() const {
	return this->name;
}

void Bureaucrat::incrementGrade() {
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

void Bureaucrat::signForm(const AForm& form) const {
	try {
		const_cast<AForm&>(form).beSigned(*this);  // ← const解除の必要がある場合のみ
		std::cout << name << " signs " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " cannot sign " << form.getName()
		          << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const
{
	try {
		form.execute(*this);
		std::cout << this->name << " executes " << form.getName() << "." << std::endl;
	} catch (std::exception& e) {
		std::cout << this->name << " cannot execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}
