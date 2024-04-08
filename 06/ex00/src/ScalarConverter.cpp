/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalarconverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:46:52 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/08 17:09:35 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) {
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	if (this != &src)
		*this = src;
	return *this;
}

static bool isAllDigit(const std::string &str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

static void printResults(char c, long i, float f, double d)
{
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else if (i > CHAR_MAX || i < CHAR_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(i) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	if (d != static_cast<float>(d))
		std::cout << std::setprecision(15);
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	std::istringstream iss(input);
	std::cout << std::setprecision(7);

	// Check if input is a char
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		std::cout << "char" << std::endl;
		char c = input[0];
		printResults(c, static_cast<long>(c), static_cast<float>(c), static_cast<double>(c));
	}
	// Check if input is an int
	else if (isAllDigit(input) || (input[0] == '-' && isAllDigit(input.substr(1))))
	{
		std::cout << "int" << std::endl;
		long i = std::atol(input.c_str());
		printResults(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i));
	}
	// Check if input is a float
	else if (input.rfind('f') == input.length() - 1 && input != "inf" && input != "-inf" && input != "nan")
	{
		std::cout << "float" << std::endl;
		float f = static_cast<float>(std::atof(input.c_str()));
		printResults(static_cast<char>(f), static_cast<long>(f), f, static_cast<double>(f));
	}
	// Otherwise, treat input as a double
	else if (input == "inf" || input == "-inf" || input == "nan" || input.find('.') != std::string::npos)
	{
		std::cout << "double" << std::endl;
		double d = std::atof(input.c_str());
		printResults(static_cast<char>(d), static_cast<long>(d), static_cast<float>(d), d);
	}
	else
		std::cout << "wrong input" << std::endl;
}
