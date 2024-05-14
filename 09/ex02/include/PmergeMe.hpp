/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:30 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/14 22:30:27 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <utility>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>


template <typename C>
void printVector(C const &input, std::string const &prefix);


class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);
	template <typename C>
	void sort(C const &input);
private:
	template <typename C>
	void makePairs(C const &input);
	void mergePairs();
	std::vector<int> buildJacobInsertionSequence(int size);
	int jacobsthal(int n);
	int binarySearch(std::vector<int>& arr, int target);
	// std::vector<std::pair<int, int>> _data;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > _data;
	std::vector<int> _sorted;
	int _straggler;
};

#include "../src/PmergeMe.tpp"