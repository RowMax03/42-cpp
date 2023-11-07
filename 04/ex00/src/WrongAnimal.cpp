/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:55:56 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:19:47 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "*Generic WrongAnimal Sounds*" << std::endl;
}