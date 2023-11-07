/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:54:39 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:20:40 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(Dog const &src);
		Dog &operator=(Dog const &rhs);
		virtual ~Dog();
		virtual void makeSound() const;
};