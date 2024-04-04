/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:32:15 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/04 16:18:59 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <fstream>

class Bureaucrat;

#include "Bureaucrat.hpp"


class AForm
{
public:
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	
	class FormNotSignedException : public std::exception
	{
		const char* what() const throw();
	};

private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;
protected:
	std::string target;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
