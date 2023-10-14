/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:38:13 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/14 22:02:59 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*		zombies;
	size_t		n_zombies = 5;
	
	zombies = zombieHorde(n_zombies, "BabaBoy");
	for (size_t i = 0; i < n_zombies; i++)
	{
		std::cout << "Zombie " << i << ": ";
		zombies[i].announce();
	}
	return (0);
}