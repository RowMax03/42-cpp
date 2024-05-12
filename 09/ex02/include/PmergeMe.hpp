/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:54:30 by mreidenb          #+#    #+#             */
/*   Updated: 2024/05/12 19:26:10 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utility>
#include <vector>
#include <queue>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &rhs);
private:
	void makePairs(std::vector<int> const &input);
	void mergePairs();
	std::vector<std::pair<int, int>> _data;
	std::vector<int> _sorted;
};