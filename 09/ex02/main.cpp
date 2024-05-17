/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:33 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/17 22:27:06 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sstream>
#include <deque>
#include <ctime>

// void printVector(std::vector<int> const &input, std::string const &prefix)
// {
// 	std::cout << prefix;
// 	for (size_t i = 0; i < input.size(); ++i) {
// 		std::cout << input[i];
// 		if (i + 1 < input.size()) {
// 			std::cout << " ";
// 		}
// 	}
// 	std::cout << std::endl;
// }

int main(int argc, char **argv)
{
	std::deque<int> input;
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [integers...]" << std::endl;
		return 1;
	}
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
	printVector(input, "Before: ");
	PmergeMe pmm;
	std::clock_t start = std::clock();
	pmm.sort(input);
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << input.size() << " elements: " << elapsed << "µs" << std::endl;
	return 0;
}