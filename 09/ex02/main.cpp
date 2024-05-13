/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:33 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/13 16:18:46 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main()
{
	int arr[] = {10, 2, 8, 6, 1, 9, 5, 3, 7, 4};
	std::vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));
	PmergeMe pmm;
	pmm.sort(input);
	return 0;
}