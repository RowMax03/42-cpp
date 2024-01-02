/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:05:36 by mreidenb          #+#    #+#             */
/*   Updated: 2024/01/02 18:40:23 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <sstream>
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;
	Bureaucrat();
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &obj);
	~Bureaucrat();
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	Bureaucrat &operator=(Bureaucrat const &obj);
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj);