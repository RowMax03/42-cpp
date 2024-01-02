/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:44:28 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/27 17:01:49 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dia("dia");
	DiamondTrap dia2(dia);
	DiamondTrap dia3("mond");

	dia.whoAmI();
	dia2.whoAmI();
	dia3 = dia;
	dia3.whoAmI();

	dia.attack( "the air" );
	dia.takeDamage( 10 );
	dia.beRepaired( 10 );
}