/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:55:14 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/16 16:44:36 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::complain(std::string level)
{
	int		i = 0;
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"debug", "info", "warning", "error"};
	while (i < 4)
	{
		if (level.compare(levels[i]) == 0)
		{
			(this->*f[i])();
			return ;
		}
		i++;
	}
	std::cout << "Error: Invalid complaint level." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "Debug: ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Info: ";
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Warning: ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Error: ";
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

