/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:30 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/18 16:53:23 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>


template <typename C>
void printContainer(C const &input, std::string const &prefix);

template <typename C>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);
	void sort(C const &input);
	C const &getSorted() const;
private:
	void makePairs(C const &input);
	void mergePairs();
	C buildJacobInsertionSequence(int size);
	int jacobsthal(int n);
	int binarySearch(C& arr, int target);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > _data;
	C _sorted;
	int _straggler;
};

#include "../src/PmergeMe.tpp"