/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 05:32:57 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 05:50:09 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_count = 0;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete _materia[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i])
				delete _materia[i];
			_materia[i] = src._materia[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (m && _count < 4)
	{
		_materia[_count] = m;
		_count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	return (NULL);
}
