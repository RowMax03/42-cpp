/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:29:46 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 20:49:30 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int printError(std::string error)
{
	std::cerr << error << std::endl;
	return 1;
}

int	main(int argc, char** argv)
{
	if (argc != 2)
		return (printError(ERR_USAGE));
	std::ifstream file(argv[1]);
	if (!file.is_open())
		return (printError(ERR_FILE));
	BitcoinExchange exchange;
	exchange.readAndValidateData();
}