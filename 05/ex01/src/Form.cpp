/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:34:43 by mreidenb          #+#    #+#             */
/*   Updated: 2024/01/02 19:53:05 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high!"; }
const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low!"; }

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute >   150)
		throw GradeTooLowException();
}

Form::~Form() {}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooHighException();
	else
		isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", form grade to sign " << form.getGradeToSign()
	   << ", form grade to execute " << form.getGradeToExecute()
	   << ", form is " << (form.getIsSigned() ? "signed" : "not signed");
	return os;
}