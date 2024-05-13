/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:30 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/13 17:10:22 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <vector>
#include <queue>
#include <iostream>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);
	void sort(std::vector<int> const &input);
private:
	void makePairs(std::vector<int> const &input);
	void mergePairs();
	std::vector<int> buildJacobInsertionSequence(int size);
	int jacobsthal(int n);
	int binarySearch(std::vector<int>& arr, int target);
	// std::vector<std::pair<int, int>> _data;
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > _data;
	std::vector<int> _sorted;
	int _straggler;
};