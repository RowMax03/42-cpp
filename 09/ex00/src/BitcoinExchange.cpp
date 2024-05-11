/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:54 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 23:15:53 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

int BitcoinExchange::getBalanceOverTime(std::ifstream &file)
{
	if (readAndValidateData())
		return 1;
	std::map<std::string, float> input = parseInput(file);
	for (std::map<std::string, float>::iterator it = input.begin(); it != input.end(); it++)
		displayBalance(it->first, it->second);
	return 0;
}

int BitcoinExchange::readAndValidateData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		printError(ERR_FILE);
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
		return printError(ERR_HEADER);
	while (std::getline(file, line))
	{
		std::string date = line.substr(0, 10);
		std::string value = line.substr(11);
		if (!validDate(date))
			return printError(ERR_INVALID_DATE);
		if (!validExchangRate(value))
			return printError(ERR_INVALID_EXCHANGE_RATE);
		_data[date] = std::stof(value);
	}
	file.close();
	return 0;
}

std::map<std::string, float> BitcoinExchange::parseInput(std::ifstream &file)
{
	std::map<std::string, float> data;
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		printError(ERR_HEADER);
	while (std::getline(file, line))
	{
		std::string date = line.substr(0, 10);
		std::string value = line.substr(13);
		data[date] = std::stof(value);
	}
	return data;

}

bool BitcoinExchange::validDate(std::string date)
{
	std::cout << date << std::endl;
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	if (date[0] < '0' || date[0] > '9')
		return false;
	if (date[1] < '0' || date[1] > '9')
		return false;
	if (date[2] < '0' || date[2] > '9')
		return false;
	if (date[3] < '0' || date[3] > '9')
		return false;
	if (date[5] < '0' || date[5] > '9')
		return false;
	if (date[6] < '0' || date[6] > '9')
		return false;
	if (date[8] < '0' || date[8] > '9')
		return false;
	if (date[9] < '0' || date[9] > '9')
		return false;
	return true;
}

bool BitcoinExchange::validExchangRate(std::string& str) {
	std::cout << str << std::endl;
	try {
		std::stof(str);
		return true;
	} catch (const std::invalid_argument& e) {
		return false;
	}
}

float BitcoinExchange::getBalance(std::string date)
{
	if (_data.find(date) != _data.end())
		return _data[date];
	return _data.lower_bound(date)->second;
}

void BitcoinExchange::displayBalance(std::string date, float &value)
{
	float balance = getBalance(date);
	if (std::isnan(value) || !validDate(date))
		printError("Error: bad input => " + date);
	else if (value > 1000)
		printError(ERR_TO_LARGE);
	else if (value < 0)
		printError(ERR_NEG_VAL);
	std::cout << date << " => " << balance << std::endl;
}