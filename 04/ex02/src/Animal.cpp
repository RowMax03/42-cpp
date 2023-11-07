/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:55:56 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 03:30:36 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
	std::cout << "*Generic Animal Sounds*" << std::endl;
}