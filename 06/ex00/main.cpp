/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:03:07 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/08 11:22:51 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
	if (argc == 1) {
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	std::string arg(argv[1]); // Convert char** to std::string
	ScalarConverter::convert(arg);
	return 0;
}