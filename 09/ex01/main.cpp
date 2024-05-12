/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:19:06 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/12 17:08:52 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int printError(std::string error)
{
	std::cout << error << std::endl;
	return 1;
}

int main(int argc, char**argv)
{
	if (argc != 2)
		return printError(ERR_USAGE);
	RPN rpn;
	return rpn.calculate(argv[1]);
}