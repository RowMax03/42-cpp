/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 03:48:05 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 05:46:11 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class AMateria;
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
		AMateria();
	public:
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & src);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};