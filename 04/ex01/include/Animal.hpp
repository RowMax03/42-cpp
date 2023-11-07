/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:52:53 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/06 23:55:20 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	Animal {
	public:
		Animal();
		Animal(Animal const &src);
		Animal &operator=(Animal const &rhs);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
	protected:
		std::string type;
};