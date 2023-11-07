/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:23:03 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:28:38 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}