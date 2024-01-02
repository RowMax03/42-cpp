/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:21:30 by mreidenb          #+#    #+#             */
/*   Updated: 2024/01/02 20:02:48 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	
	Bureaucrat *b2 = new Bureaucrat("b2", 150);
	try
	{
		Bureaucrat *b1 = new Bureaucrat("b1", 1);
		std::cout << *b1 << std::endl;
		try 
		{
			Form *f1 = new Form("f1", 1, 1);
			std::cout << *f1 << std::endl;
			b1->decrementGrade();
			b1->signForm(*f1);
			b1->incrementGrade();
			b1->signForm(*f1);
			delete f1;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete b1;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << *b2 << std::endl;
		b2->decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *b3 = new Bureaucrat("b3", 151);
		std::cout << *b3 << std::endl;
		delete b3;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *b4 = new Bureaucrat("b4", 0);
		std::cout << *b4 << std::endl;
		delete b4;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat *b5 = new Bureaucrat("b5", 42);
		std::cout << *b5 << std::endl;
		delete b5;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b2->incrementGrade();
		std::cout << *b2 << std::endl;
		delete b2;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// system("leaks Bureaucrat");
}