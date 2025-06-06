#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	const std::string& getTarget() const;
	void execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif
