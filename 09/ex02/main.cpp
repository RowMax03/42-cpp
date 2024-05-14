/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:33 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/14 14:08:52 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sstream>

int main(int argc, char **argv)
{
	std::vector<int> input;
	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		int x;
		if (ss >> x) {
			input.push_back(x);
		} else {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
	}

	PmergeMe pmm;
	pmm.sort(input);
	return 0;
}