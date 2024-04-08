/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:03:07 by mreidenb          #+#    #+#             */
/*   Updated: 2024/04/08 19:05:08 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.n = 42;
	data.d = 42.42;
	std::cout << "Data: " << data.n << " " << data.d << std::endl;
	size_t adress = (size_t)&data; // c style cast
	std::cout << "Adress: " << adress << std::endl;
	uintptr_t raw = Serializer::serialize(&data); // cpp style cast with type checking
	std::cout << "Raw: " << raw << std::endl;
	Data* ptr = Serializer::deserialize(raw);
	std::cout << "Data: " << ptr->n << " " << ptr->d << std::endl;
	return 0;
}