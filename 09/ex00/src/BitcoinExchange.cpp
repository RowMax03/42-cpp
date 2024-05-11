/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:54 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 20:29:46 by mreidenb         ###   ########.fr       */
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

void BitcoinExchange::readAndValidateData()
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: Invalid header" << std::endl;
		return;
	}
	while (std::getline(file, line))
	{
		std::string date = line.substr(0, 10);
		std::string value = line.substr(11);
		if (!validDate(date) || !validExchangRate(value))
		{
			std::cerr << "Error: Invalid data" << std::endl;
			return;
		}
		_data[date] = std::stof(value);
	}
	file.close();
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