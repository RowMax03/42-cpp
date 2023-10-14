/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:25:42 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/14 20:28:26 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombie = newZombie("Frankenstein");
	zombie->announce();
	randomChump("Jefrey Dahmer");
	delete zombie;
	return (0);
}
