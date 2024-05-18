/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:20:25 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/18 17:46:07 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

#define ERR_USAGE "Error: Usage: ./RPN \"1 1 +\""
#define ERR_SINGLE_DIGIT "Error: The numbers passed have to be single digit (subject req)"
#define ERR_UNSUPORTED_TOKEN "Error: Token unsuported, only \"+ - / *\" are allowed"
#define ERR_STACK_EMPTY "Error: Stack went empty when trying to performe operation, check input"

int printError(std::string error);

class RPN
{
public:
	RPN();
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &other);
	int calculate(const std::string &str);
private:
	std::stack<int> _stack;
	int parse(const std::string &str);
	int performe_operation(char &operant);
};