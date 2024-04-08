/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalarconverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:46:52 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/08 12:21:12 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <limits>
#include <iomanip>

void ScalarConverter::convert(const std::string &input)
{
	// Handle char
	std::istringstream iss(input);
	std::cout << std::setprecision(7);
	int i;
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		char c = input[0];
		if (std::isprint(c))
		{
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
			return ;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	else if (iss >> i && i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max())
	{
		char c = static_cast<char>(i);
		if (std::isprint(c))
		{
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	// Handle int
	iss.clear();
	iss.str(input);
	if (iss >> i)
	{
		std::cout << "int: " << i << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}
	// Handle float
	iss.clear();
	iss.str(input);
	float f;
	if (iss >> f)
	{
		std::cout << "float: " << f << "f" << std::endl;
	}
	else {
		if (input == "-inff" || input == "-inf")
			f = -std::numeric_limits<float>::infinity();
		else if (input == "nan" || input == "nanf")
			f = std::numeric_limits<float>::quiet_NaN();
		else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
			f = std::numeric_limits<float>::infinity();
		if (std::isdigit(input[1]))
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	std::cout << std::setprecision(15);
	// Handle double
	iss.clear();
	iss.str(input);
	double d;
	if (iss >> d)
	{
		std::cout << "double: " << d << std::endl;
	}
	else if (input == "nan" || input == "inf" || input == "-inf")
	{
		std::cout << "double: " << input << std::endl;
	}
	else
	{
		std::cout << "double: impossible" << std::endl;
	}
}