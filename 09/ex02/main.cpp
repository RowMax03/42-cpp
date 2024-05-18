/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:33 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/18 16:44:05 by mreidenb         ###   ########.fr       */
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
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [integers...]" << std::endl;
		return 1;
	}
	std::vector<int> inputVec;
	std::deque<int> inputDeque;
	for (int i = 1; i < argc; ++i) {
		std::stringstream ss(argv[i]);
		int x;
		if (ss >> x) {
			inputVec.push_back(x);
			inputDeque.push_back(x);
		} else {
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
	}
	printContainer(inputVec, "Before: ");
	PmergeMe<std::vector<int> > pmmVec;
	std::clock_t start = std::clock();
	pmmVec.sort(inputVec);
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	printContainer(pmmVec.getSorted(), "After: ");
	std::cout << "Time to process a range of " << inputVec.size() << " elements with std::vector: " << elapsed << "µs" << std::endl;
	PmergeMe<std::deque<int> > pmmDeque;
	start = std::clock();
	pmmDeque.sort(inputDeque);
	end = std::clock();
	elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << inputDeque.size() << " elements with std::deque: " << elapsed << "µs" << std::endl;
	return 0;
}