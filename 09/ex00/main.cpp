/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:29:46 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 20:17:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv)
{
	(void)argv;
	if (argc != 2)
		return (1);
	BitcoinExchange exchange;
	exchange.readAndValidateData();
}