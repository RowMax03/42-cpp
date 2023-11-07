/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:23:03 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 03:29:09 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &src)
	{
		this->type = src.type;
		if (this->_brain)
			delete this->_brain;
	this->_brain = new Brain(*src._brain);
	}
	*this = src;
}

Cat &Cat::operator=(Cat const &rhs) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	if (this->_brain)
		delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}