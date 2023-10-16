/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:39:00 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/16 16:40:18 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}