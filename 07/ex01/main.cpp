/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:33:41 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/10 14:48:40 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

int main()
{
	int intArray[5] = {1, 2, 3, 4, 5};
	float floatArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[5] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter(intArray, 5, print);
	std::cout << "floatArray: ";
	iter(floatArray, 5, print);
	std::cout << "stringArray: ";
	iter(stringArray, 5, print);

	std::cout << std::endl << "\n -------- incrementation example -------- \n" << std::endl; 
	std::cout << "intArray: ";
	iter(intArray, 5, increment);
	iter(intArray, 5, print);
	std::cout << "floatArray: ";
	iter(floatArray, 5, increment);
	iter(floatArray, 5, print);
	// std::cout << "stringArray: ";
	// iter(stringArray, 5, increment);

	return 0;
}