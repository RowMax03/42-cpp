/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:32:15 by mreidenb          #+#    #+#             */
/*   Updated: 2024/03/20 12:13:48 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

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

private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	virtual void beSigned(Bureaucrat &bureaucrat) = 0; // Pure virtual function
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
