/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:44:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/02 17:47:25 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap("Barack Obama");
	ScavTrap scavTrap2(scavTrap);
	ScavTrap scavTrap3("George W Bush");

	scavTrap.attack("Isis");
	scavTrap3.guardGate();
	scavTrap.guardGate();
	scavTrap.takeDamage(2);
	scavTrap.beRepaired(2);
	scavTrap.attack("Republicans");
	scavTrap.attack("Socialists");
	scavTrap.attack("Some random guy");
	scavTrap.attack("Some random 3 World Country");
	scavTrap.attack("Republicans");
	scavTrap.attack("George W Bush");
	scavTrap.attack("Republicans");
	scavTrap.attack("Republicans");
	scavTrap.beRepaired(2);
	scavTrap.attack("Republicans");
	scavTrap2.attack("Republicans");
	
}