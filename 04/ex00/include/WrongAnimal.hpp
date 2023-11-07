/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:33:00 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:34:29 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class	WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator=(WrongAnimal const &rhs);
		virtual ~WrongAnimal();
		std::string getType() const;
		void makeSound() const;
	protected:
		std::string type;
};