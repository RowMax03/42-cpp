/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:54:51 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 01:22:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(Cat const &src);
		Cat &operator=(Cat const &rhs);
		virtual ~Cat();
		virtual void makeSound() const;
	private:
		Brain *_brain;
};