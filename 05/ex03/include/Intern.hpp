/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:54:43 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/04 17:32:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	// Factory functions
	static AForm* createRobotomyRequestForm(std::string const &target) {
		return new RobotomyRequestForm(target);
	}

	static AForm* createShrubberyCreationForm(std::string const &target) {
		return new ShrubberyCreationForm(target);
	}

	static AForm* createPresidentialPardonForm(std::string const &target) {
		return new PresidentialPardonForm(target);
	}


public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern &other);

	AForm *makeForm(std::string formName, std::string target);
};