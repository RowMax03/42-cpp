/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:38:13 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/05 17:00:26 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombies.hpp"

int	main()
{
	Zombie*		zombies;
	size_t		n_zombies = 5;
	
	zombies = zombieHorde(n_zombies, "BabaBoy");
	for (size_t i = 0; i < n_zombies; i++)
	{
		std::cout << "Zombie " << i << ": ";
		zombies[i].announce();
	}
	delete [] zombies;
	return (0);
}