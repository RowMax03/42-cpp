/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:35:43 by mreidenb          #+#    #+#             */
/*   Updated: 2023/11/05 16:55:09 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombies.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie*	zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return (zombies);
}