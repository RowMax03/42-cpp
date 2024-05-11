/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:30:28 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/11 20:29:37 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>

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
	void readAndValidateData();
	bool validDate(std::string date);
	bool validExchangRate(std::string& str);
	float getBalance(std::string date);
};