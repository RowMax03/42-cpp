/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:54 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/18 17:28:49 by mreidenb         ###   ########.fr       */
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
	getBalanceForInput(file);
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
		_data[date] = std::stod(value);
	}
	file.close();
	return 0;
}

void BitcoinExchange::getBalanceForInput(std::ifstream &file)
{
	std::string line;
	float f_value;
	std::string date;

	std::getline(file, line);
	if (line != "date | value")
		printError(ERR_HEADER);
	while (std::getline(file, line))
	{
		bool valid = true;
		if (line.length() >= 10)
			date = line.substr(0, 10);
		else
			date = "[empty]";
		if (line.length() >= 14 && line[11] == '|')
		{
			std::string value = line.substr(13);
			f_value = std::stof(value);
		}
		else
			valid = false;
		valid = valid && validDate(date);
		displayBalance(date, f_value, valid);
	}
}

bool BitcoinExchange::validDate(std::string date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	return true;
}

bool BitcoinExchange::validExchangRate(std::string& str) {
	try {
		std::stof(str);
		return true;
	} catch (const std::invalid_argument& e) {
		return false;
	}
}

double BitcoinExchange::getBalance(std::string date)
{
	if (_data.find(date) != _data.end())
		return _data[date];

	std::map<std::string, double>::iterator it = _data.upper_bound(date);
	if (it != _data.begin())
	{
		it--;
		return it->second;
	}
	return _data.lower_bound(date)->second;
}

void BitcoinExchange::displayBalance(std::string date, float &value, bool valid)
{
	double balance = getBalance(date);
	if (!valid || !validDate(date))
		printError("Error: bad input => " + date);
	else if (value > 1000)
		printError(ERR_TO_LARGE);
	else if (value < 0)
		printError(ERR_NEG_VAL);
	else
		std::cout << date << " => " << value << " = "<< std::setprecision(10) << balance * value << std::setprecision(7) << std::endl;
	// std::cout << "balance: " << balance << "value: "  << value <<std::endl;
}