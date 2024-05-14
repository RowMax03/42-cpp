/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:24:48 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/14 22:28:24 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// template <typename C>
// void printVector(C const &input, std::string const &prefix)
// {
// 	std::cout << prefix;
// 	for (auto const &i : input)
// 		std::cout << i << " ";
// 	std::cout << std::endl;
// }

template <typename C>
void printVector(C const &input, std::string const &prefix)
{
	std::cout << prefix;
	for (size_t i = 0; i < input.size(); ++i) {
		std::cout << input[i];
		if (i + 1 < input.size()) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

template <typename C>
void PmergeMe::makePairs(C const &input)
{
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 < input.size())
        {
            _data.push(std::make_pair(input[i] < input[i + 1] ? input[i + 1] : input[i],
                input[i] < input[i + 1] ? input[i] : input[i + 1])); 
        }
        else
            _straggler = input[i];
    }
}

template <typename C>
void PmergeMe::sort(C const &input)
{
	makePairs(input);
	mergePairs();
}