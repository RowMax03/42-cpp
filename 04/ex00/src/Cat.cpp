/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:23:03 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:28:38 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &src) {
	std::cout << "Cat copy constructor called" << std::endl;
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
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}