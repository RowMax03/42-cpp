/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:32:09 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/18 17:45:31 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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

int RPN::calculate(const std::string &str)
{
	if (parse(str))
		return 1;
	std::cout << _stack.top() << std::endl;
	return 0;
}


int RPN::parse(const std::string &str)
{
	std::istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, ' '))
	{
		if (std::isdigit(token[0]))
		{
			std::istringstream issToken(token);
			int to_stack;
			issToken >> to_stack;
			if (to_stack >= 0 && to_stack <= 9) 
				_stack.push(to_stack);
			else
				return printError(ERR_SINGLE_DIGIT);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (performe_operation(token[0]))
				return 1;
		}
		else
			return printError(ERR_UNSUPORTED_TOKEN);
	}
	return 0;
}
int RPN::performe_operation(char &operant)
{
	if (_stack.empty())
		return printError(ERR_STACK_EMPTY);
	int number2 = _stack.top();
	_stack.pop();
	if (_stack.empty())
		return printError(ERR_STACK_EMPTY);
	int number1 = _stack.top();
	_stack.pop();
	if (operant == '+')
		_stack.push(number1 + number2);
	else if (operant == '-')
		_stack.push(number1 - number2);
	else if (operant == '*')
		_stack.push(number1 * number2);
	else if (operant == '/')
		_stack.push(number1 / number2);
	return 0;
}
