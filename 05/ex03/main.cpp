/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:29:06 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/04 17:48:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main( void )
{
	Bureaucrat randiAndi = Bureaucrat("Bureaucrat", 1);
	Intern someRandomIntern;
	AForm* rrf;
	AForm* shrubbery;
	AForm* ppf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	shrubbery = someRandomIntern.makeForm("shrubbery creation", "Bender");
	ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	someRandomIntern.makeForm("nonexistent form", "Bender");
	
	std::cout << *rrf << std::endl;
	std::cout << *shrubbery << std::endl;
	try {
		shrubbery->beSigned(randiAndi);
		shrubbery->execute(randiAndi);
		rrf->execute(randiAndi);
		ppf->execute(randiAndi);
		ppf->beSigned(randiAndi);
		ppf->execute(randiAndi);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *rrf << std::endl;
	
}
