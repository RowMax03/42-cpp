/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:32:09 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/12 16:01:57 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

int RPN::parse(const std::string &str)
{
	std::istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, ' '))
	{
		if (std::isdigit(token[0]))
		{
			int to_stack = std::stoi(token)
			if (to_stack >= 0 && to_stack <= 9) 
				_stack.push(to_stack);
			else
				return printError(ERR_SINGLE_DIGIT);
		}
		else if ()
	}
}
