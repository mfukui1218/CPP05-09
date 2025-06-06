#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
public:
	AForm(const std::string& name, int
			signGrade, int executeGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	void beSigned(const Bureaucrat& b);
	void executeCheck(const Bureaucrat& executor) const;
	virtual void execute(const Bureaucrat& executor) const = 0;
};

#endif
