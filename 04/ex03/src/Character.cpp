/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 04:08:13 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/07 05:17:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_name = name;
	std::cout << "Character " << _name << " is born!" << std::endl;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << "Character " << _name << " is dead!" << std::endl;
}

Character & Character::operator=(Character const & src)
{
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!_inventory[i])
			{
				_inventory[i] = m;
				std::cout << "Character " << _name << " equiped " << m->getType() << "!" << std::endl;
				return ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << "Character " << _name << " unequiped " << _inventory[idx]->getType() << "!" << std::endl;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}
