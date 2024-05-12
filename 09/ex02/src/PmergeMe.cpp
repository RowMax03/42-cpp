/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:28 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/12 19:24:17 by mreidenb         ###   ########.fr       */
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
	for (size_t i = 0; i < input.size(); i += 2)
	{
		if (i + 1 < input.size())
		{
			// Compare the two values and create a pair with the smaller value first
			_data.push_back(std::make_pair(input[i] < input[i + 1] ? input[i] : input[i + 1], 
				input[i] < input[i + 1] ? input[i + 1] : input[i])); 
		}
		// If there is only one value left, create a pair with the same value twice
		else
			_data.push_back(std::make_pair(input[i], input[i]));
	}
}

void PmergeMe::mergePairs()
{
	std::priority_queue<std::pair<int, int>> pq;
	for (int i = 0; i < _data.size(); ++i) {
    	pq.push(std::make_pair(_data[i].second, i));  // _data[i].second is the larger element in the pair
}
}