/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:59:31 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/02 18:04:51 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " has been created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " has been cloned" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src)
{
	this->_name = src._name; 
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "FragTrap " << this->_name << " has been cloned" << std::endl;
	return (*this);
}

void FragTrap::attack(std::string const & target)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		return ;
	}
	else
		std::cout << "FragTrap " << this->_name << " has no energy left!" << std::endl;
}

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a High Five" << std::endl;
	std::cout << this->_name << ": Hey man up for a High Five?" << std::endl;
}