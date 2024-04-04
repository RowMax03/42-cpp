/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:34:43 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/04 16:19:26 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw() { return "Form grade too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Form grade too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form not signed!"; }

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute >   150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
	{
		target = other.target;
		isSigned = other.isSigned;
	}
	return *this;
}


std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooHighException();
	else
		isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", form grade to sign " << form.getGradeToSign()
	   << ", form grade to execute " << form.getGradeToExecute()
	   << ", form is " << (form.getIsSigned() ? "signed" : "not signed");
	return os;
}
