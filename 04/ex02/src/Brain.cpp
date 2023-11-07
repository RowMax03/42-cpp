/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:10:50 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 01:15:19 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(Brain const &rhs) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string idea) {
	this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	return this->_ideas[index];
}
