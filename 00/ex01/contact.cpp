/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:34:03 by mreidenb          #+#    #+#             */
/*   Updated: 2023/10/01 19:45:28 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.h"

contact::contact(void)
{
	return ;
}

contact::~contact(void)
{
	return ;
}

void	contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
	return ;
}

void	contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
	return ;
}
void	contact::set_number(std::string number)
{
	this->number = number;
	return ;
}
void	contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
	return ;
}

void	contact::set_dark_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
	return ;
}

std::string	contact::get_contact(void)
{
	std::string	contact;

	contact = this->first_name + "\n" +
		this->last_name + "\n" +
		this->nickname + "\n" +
		this->number + "\n" +
		this->darkest_secret + "\n" ;
	return (contact);
}