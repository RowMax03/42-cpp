/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:26:18 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/01 20:03:44 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
#include <iomanip>
#include <sstream>
#include <string>

phonebook::phonebook(void)
{
	this->contact_count = 0;
	return ;
}

phonebook::~phonebook(void)
{
	return ;
}

void	phonebook::add(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	number;
	std::string	darkest_secret;

	while (first_name.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, first_name);
	}
	while (last_name.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, last_name);
	}
	while (nickname.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, nickname);
	}
	while (number.empty())
	{
		std::cout << "Enter number: ";
		std::getline(std::cin, number);
	}
	while (darkest_secret.empty())
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, darkest_secret);
	}
	this->contacts[this->contact_index].set_first_name(first_name);
	this->contacts[this->contact_index].set_last_name(last_name);
	this->contacts[this->contact_index].set_number(number);
	this->contacts[this->contact_index].set_nickname(nickname);
	this->contacts[this->contact_index].set_dark_secret(darkest_secret);
	this->contact_index++;
	if (contact_count < 8)
		this->contact_count++;
	else if (contact_index == 8)
		this->contact_index = 0;
	return ;
}

void	phonebook::search(void)
{
	int			i;
	std::string	contact;
	std::string	tmp;

	i = 0;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < this->contact_count)
	{
		contact = this->contacts[i].get_contact();
		std::istringstream contact_stream(contact);
		if (contact_stream.fail())
			return ;
		std::cout << std::setw(10) << i << "|";
		for (int j = 0; j < 3; j++)
		{	
			std::getline(contact_stream, tmp);
			if (tmp.length() > 10)
			{
				tmp.resize(9);
				tmp += ".";
			}
			std::cout << std::setw(10) << tmp << "|";
		}
		std::cout << std::endl;
		i++;
	}
	int index = -1;
	while (index < 0 || index > this->contact_count)
	{
		std::cout << "Enter index of Contact: ";
		std::getline(std::cin, tmp);
		if (std::all_of(tmp.begin(), tmp.end(), ::isdigit))
			index = std::stoi(tmp);
	}
	std::cout << this->contacts[std::stoi(tmp)].get_contact();
}
