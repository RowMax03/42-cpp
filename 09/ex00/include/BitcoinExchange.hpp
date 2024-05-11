/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:28 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 23:47:39 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

#define ERR_USAGE "Error: Usage: ./btc <input.txt>"
#define ERR_FILE "Error: Could not open file"
#define ERR_HEADER "Error: Invalid header"
#define ERR_TO_LARGE "Error: too large a number."
#define ERR_NEG_VAL "Error: not a positive number."
#define ERR_INVALID_DATE "Error: Invalid date in db."
#define ERR_INVALID_EXCHANGE_RATE "Error: Invalid exchange rate in db."

int printError(std::string error);

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	int getBalanceOverTime(std::ifstream &file);
private:
	std::map<std::string, float> _data;
	int readAndValidateData();
	bool validDate(std::string date);
	bool validExchangRate(std::string& str);
	float getBalance(std::string date);
	void displayBalance(std::string date, float &value);
	void getBalanceForInput(std::ifstream &file);
};