/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:28 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/12 18:21:51 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _data()
{
}
PmergeMe::PmergeMe(PmergeMe const &src) : _data(src._data)
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_data = rhs._data;
	}
	return *this;
}

void PmergeMe::makePairs(std::vector<int> const &input)
{
	
}