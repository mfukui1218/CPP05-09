#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[3])(const std::string&) = {
		createShrubbery,
		createRobotomy,
		createPardon
	};

	for (int i = 0; i < 3; ++i) {
		if (forms[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern cannot create unknown form: " << name << std::endl;
	return NULL;
}
