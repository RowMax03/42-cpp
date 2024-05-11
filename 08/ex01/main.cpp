/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:55:35 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 16:40:27 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
Span sp = Span(6);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
sp.addNumber(-123918830);
try
{
	sp.addRange(-4, 1);
}
catch (const std::exception& e)
{
	std::cout << e.what() << std::endl;
}
std::cout << "Sp shortest Span: " << sp.shortestSpan() << std::endl;
std::cout << "Sp longest Span: " << sp.longestSpan() << std::endl;

Span sp2 = Span(2);
Span noSpan = Span(1);
try
{
	sp2.addRange(-4, -3);
	std::cout << "Sp2 shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Sp2 longest Span: " << sp2.longestSpan() << std::endl;
	noSpan.addNumber(42);
	// noSpan.addNumber(-42);
	std::cout << "noSpan longest Span: " << noSpan.longestSpan() << std::endl;
}
catch (const std::exception& e)
{
	std::cout << e.what() << std::endl;
}

Span huge = Span(20002);
try
{
	huge.addRange(-10000, 10000);
	std::cout << "huge shortest Span: " << huge.shortestSpan() << std::endl;
	std::cout << "huge longest Span: " << huge.longestSpan() << std::endl;
}
catch (const std::exception& e)
{
	std::cout << e.what() << std::endl;
}
return 0;
}