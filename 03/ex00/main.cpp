/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:44:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/01 18:41:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Barack Obama");
	ClapTrap clapTrap2(clapTrap);
	ClapTrap clapTrap3("George W Bush");

	clapTrap.attack("Isis");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(2);
	clapTrap.attack("Republicans");
	clapTrap.attack("Socialists");
	clapTrap.attack("Some random guy");
	clapTrap.attack("Some random 3 World Country");
	clapTrap.attack("Republicans");
	clapTrap.attack("George W Bush");
	clapTrap.attack("Republicans");
	clapTrap.attack("Republicans");
	clapTrap.beRepaired(2);
	clapTrap.attack("Republicans");
	clapTrap2.attack("Republicans");
	
}