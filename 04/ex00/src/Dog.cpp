/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:09:51 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:27:46 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wuff Wuff" << std::endl;
}