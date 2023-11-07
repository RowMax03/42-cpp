/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:09:51 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 01:40:06 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog &Dog::operator=(Dog const &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Wuff Wuff" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	if (this->_brain)
		delete this->_brain;
}
