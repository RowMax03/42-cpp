/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:33:17 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 00:33:54 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		WrongCat &operator=(WrongCat const &rhs);
		virtual ~WrongCat();
		void makeSound() const;
};