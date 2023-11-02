/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:44:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/02 18:26:28 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("Barack Obama");
	FragTrap fragTrap2(fragTrap);
	FragTrap fragTrap3("George W Bush");

	fragTrap.attack("Isis");
	fragTrap3.highFiveGuys();
	fragTrap.takeDamage(2);
	fragTrap.beRepaired(2);
	fragTrap.attack("Republicans");
	fragTrap.attack("Socialists");
	fragTrap.attack("Some random guy");
	fragTrap.attack("Some random 3 World Country");
	fragTrap.attack("Republicans");
	fragTrap.attack("George W Bush");
	fragTrap.attack("Republicans");
	fragTrap.attack("Republicans");
	fragTrap.beRepaired(2);
	fragTrap.attack("Republicans");
	fragTrap2.attack("Republicans");
	
}