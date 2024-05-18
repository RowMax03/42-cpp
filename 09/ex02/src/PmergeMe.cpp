/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:28 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/18 16:25:13 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C>
PmergeMe<C>::PmergeMe() : _data()
{
	_straggler = -1;
}
template <typename C>
PmergeMe<C>::PmergeMe(PmergeMe const &src) : _data(src._data)
{
}

template <typename C>
PmergeMe<C>::~PmergeMe()
{
}

template <typename C>
PmergeMe<C> &PmergeMe<C>::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		_data = rhs._data;
	}
	return *this;
}

template <typename C>
void PmergeMe<C>::mergePairs()
{
	C pend;
	while (!_data.empty())
	{
		std::pair<int, int> smallestPair = _data.top();
		_data.pop();

		_sorted.push_back(smallestPair.first);
		pend.push_back(smallestPair.second);
	}

	// Insert the first element of pend into _sorted
	_sorted.insert(_sorted.begin(), pend[0]);
	pend.erase(pend.begin());

	// Build the Jacobsthal insertion sequence
	std::vector<int> jacobSeq = buildJacobInsertionSequence(pend.size());

	// Insert the remaining elements of pend into _sorted using the Jacobsthal sequence
	size_t iterator = 0;
	size_t jacobIndex = 0;
	bool last = false;
	while (iterator < pend.size())
	{
		int insertPos;
		if (!jacobSeq.empty() && last != true)
		{
			insertPos = jacobSeq[0];
			jacobSeq.erase(jacobSeq.begin());
			last = true;
		}
		else
		{
			if (std::find(jacobSeq.begin(), jacobSeq.end(), iterator) != jacobSeq.end())
				iterator++;
			insertPos = iterator;
			last = false;
		}
		int item = pend[insertPos];
		int insertionPoint = binarySearch(_sorted, item);
		_sorted.insert(_sorted.begin() + insertionPoint, item);

		iterator++;
		jacobIndex++;
	}

	// If there's a straggler, perform a binary search and insert it into _sorted
	if (_straggler != -1)
	{
		int insertPos = binarySearch(_sorted, _straggler);
		_sorted.insert(_sorted.begin() + insertPos, _straggler);
	}
	printVector(_sorted, "After: ");
}

template <typename C>
C PmergeMe<C>::buildJacobInsertionSequence(int arrayLen)
{
	C endSequence;
	int jacobIndex = 3; // The first one that matters

	// Loop through and create the sequence
	while (jacobsthal(jacobIndex) < arrayLen - 1)
	{
		endSequence.push_back(jacobsthal(jacobIndex));
		jacobIndex++;
	}

	return endSequence;
}

template <typename C>
int PmergeMe<C>::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return 2 * jacobsthal(n - 1) + jacobsthal(n - 2);
}

template <typename C>
int PmergeMe<C>::binarySearch(std::vector<int>& arr, int target)
{
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return left;
}