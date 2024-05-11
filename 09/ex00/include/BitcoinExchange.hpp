/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:28 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 20:49:45 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>

#define ERR_USAGE "Error: Usage: ./btc <input.txt>"
#define ERR_FILE "Error: Could not open file"

int printError(std::string error);

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	void getBalanceOverTime(std::string date);
// private:
	std::map<std::string, float> _data;
	int readAndValidateData();
	bool validDate(std::string date);
	bool validExchangRate(std::string& str);
	float getBalance(std::string date);
};